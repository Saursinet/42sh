/*
** find_funct.c for minishell in /home/saurs_f/rendu/PSU_2014_minishell1
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Jan 26 23:32:14 2015 Florian Saurs
** Last update Sun May 31 19:29:58 2015 guillaume wilmot
*/

#include "minishell.h"

char	*get_folder(char *str)
{
  int	i;
  int	j;
  char	*folder;

  i = 0;
  j = 0;
  while (str && str[i])
    i++;
  while (i > 0 && str[i] != '/')
    i--;
  if (str[i] != '/')
    return (NULL);
  if ((folder = malloc((i + 2) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (j < i)
    {
      folder[j] = str[j];
      j++;
    }
  folder[j] = '\0';
  return (folder);
}

char	*check_exist(char **el_camino, char **tabl)
{
  char	*folder;
  char	*str;
  int	i;

  str = tabl[0];
  i = 0;
  if (str == NULL || match(str, "echo") ||
      match(str, "history") || match(str, "env"))
    return (NULL);
  if ((folder = get_folder(str)) != NULL)
    {
      free(folder);
      return ((access(str, 0) == -1) ? NULL : str);
    }
  if (el_camino != NULL && el_camino[i] != NULL)
    str = my_strcat(el_camino[i], tabl[0]);
  while (access(str, 0) == -1 && el_camino[i] != NULL)
    str = my_strcat(el_camino[i++], tabl[0]);
  if (el_camino[i] == NULL)
    {
      free(str);
      str = NULL;
    }
  return (str);
}

char	*find_my_funct(char **env, char *my_src)
{
  int	i;
  int	c;
  int	j;

  i = 0;
  c = 5;
  j = 0;
  while (env[i] != NULL && my_strncmp("PATH=", env[i], 4) != 0)
    ++i;
  if (env[i] != NULL)
    {
      while (env[i][c] != 0)
	++c;
      if ((my_src = malloc(sizeof(char) * (c - 4))) == NULL)
	return (NULL);
      c = 5;
      while (env[i][c] != 0)
	my_src[j++] = env[i][c++];
      my_src[j] = 0;
    }
  else
    return ("\0");
  return (my_src);
}

char	*get_user(char **env, char *my_src)
{
  int	i;
  int	c;
  int	j;

  i = 0;
  c = 5;
  j = 0;
  while (env[i] != NULL && my_strncmp("USER=", env[i], 4) != 0)
    ++i;
  if (env[i] != NULL)
    {
      while (env[i][c] != 0)
	++c;
      if ((my_src = malloc(sizeof(char) * (c - 4))) == NULL)
	return (NULL);
      c = 5;
      while (env[i][c] != 0)
	my_src[j++] = env[i][c++];
      my_src[j] = 0;
    }
  else
    return ("Unknown");
  return (my_src);
}
