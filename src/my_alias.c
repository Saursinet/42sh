/*
** my_alias.c for minishell in /home/saurs_f/rendu/PSU_2014_minishell1
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sun Feb  1 12:28:05 2015 Florian Saurs
** Last update Sun May 24 20:42:17 2015 guillaume wilmot
*/

#include "minishell.h"

char	**print_my_event(char **arg)
{
  printf("There is a wrong alias in alias.txt:\n");
  printf("The presentation is: alias [NAME]=\'[REPLACE]\'\n");
  arg[0] = NULL;
  return (arg);
}

char	**check_tab(char **arg)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (arg[i] != NULL)
    {
      j = 0;
      if (my_strncmp("alias ", arg[i], 5) != 0)
	return (print_my_event(arg));
      while (arg[i][j] != 0 && arg[i][j] != '=' && arg[i][j + 1] != '\'')
	++j;
      if (arg[i][j] == 0 || arg[i][j] == '\n')
	{
	  printf("%c\n", arg[i][j]);
	  printf("There is a wrong alias in alias.txt:\n %s \n", arg[i]);
	  printf("The presentation is: alias [NAME]=\'[REPLACE]\'\n");
	  arg[0] = NULL;
	  return (arg);
	}
      arg[i] = &arg[i][6];
      ++i;
    }
  return (arg);
}

char	*change_my_str(char *str, char *arg, int length)
{
  int	j;
  int	len;
  char	*new_str;

  arg = &arg[length];
  len = my_strlen(str) - length + my_strlen(arg) + 2;
  if ((new_str = malloc(sizeof(char) * len)) == NULL)
    return (str);
  j = 0;
  str = &str[length - 2];
  length = 0;
  while (arg[j] != 0 && arg[j] != '\'')
    {
      new_str[j] = arg[j];
      ++j;
    }
  while (str[length] != 0)
    new_str[j++] = str[length++];
  new_str[j] = 0;
  return (new_str);
}
