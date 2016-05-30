/*
** command.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Fri May 22 01:30:50 2015 Kévin Empociello
** Last update Sun May 31 23:05:02 2015 guillaume wilmot
*/

#include "edit.h"
#include "minishell.h"

int	command_is_good(char *command, char **env)
{
  int	i;
  int	check;
  char	*s;
  char	*tmp;
  char	*str;

  i = ((s = NULL) == NULL) ? 0 : 0;
  check = 0;
  if ((i = place_env(env)) == -1)
    return (-1);
  else
    {
      tmp = cpy(env[i]);
      s = strtok(tmp, ":");
      while ((s = strtok(NULL, ":")) != NULL)
	{
	  if (access((str = concatenate(s, command, '/')), R_OK) == 0)
	    check = 1;
	  free(str);
	}
      free(tmp);
    }
  return (((check == 0) ? -1 : 0));
}

int	is_bult(char *str)
{
  if ((strncmp(str, "cd", 2) == 0) || (strncmp(str, "env", 3) == 0) ||
      (strncmp(str, "unsetenv", 8) == 0) || (strncmp(str, "setenv", 6) == 0) ||
      (strncmp(str, "echo", 4) == 0) || (strncmp(str, "history", 7) == 0) ||
      (strncmp(str, "exit", 4) == 0) || (strncmp(str, "fg", 2) == 0) ||
      (strncmp(str, "!", 1) == 0) || (strncmp(str, "ll", 2) == 0) ||
      (strncmp(str, "la", 2) == 0) || (strncmp(str, "ne", 2) == 0))
      return (0);
    return (-1);
}

int	check_command(char *str, char **env)
{
  if (access(str, F_OK) == 0)
    return (0);
  if (command_is_good(str, env) == 0 || is_bult(str) == 0)
    return (0);
  else
    return (-1);
}

char	**cut_command(char *str)
{
  char  **tabl;
  int   i;
  int   k;
  int   j;

  i = 0;
  j = 0;
  if ((tabl = malloc((my_strlen(str) + 2) * sizeof(char *))) == NULL)
    return (NULL);
  while (str && str[i])
    {
      while (str && str[i] && str[i] == ' ')
	  i++;
      if ((tabl[j] = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
        return (NULL);
      k = 0;
      while (str && str[i] && str[i] != ' ')
        tabl[j][k++] = str[i++];
      tabl[j][k] = '\0';
      while (str && str[i] && str[i] == ' ')
        i++;
      j++;
    }
  tabl[j] = NULL;
  return (tabl);
}

char	*change_command(char *cmd, char *new_cmd)
{
  char	*new;
  int	j;
  int	i;

  i = 0;
  j = 0;
  if (new_cmd == NULL)
    return (cmd);
  if ((new = malloc((strlen(cmd) + strlen(new_cmd)) * sizeof(char))) == NULL)
    return (NULL);
  while (new_cmd && new_cmd[i] != '\0')
    {
      new[i] = new_cmd[i];
      i++;
    }
  while (cmd && cmd[j] != '\0' && cmd[j] != ' ')
    j++;
  while (cmd && cmd[j] != '\0' && cmd[j] != ' ')
    new[i++] = cmd[j++];
  new[i] = '\0';
  return (new);
}
