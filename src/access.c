/*
** access.c for  in /home/barrie_j/Documents/rendu/Sem_2/PSU/PSU_2014_42sh/RedBlackTree
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Thu May 21 23:28:43 2015 Jean BARRIERE
** Last update Sun May 24 05:25:37 2015 Florian Saurs
*/

#include "types.h"

void	copy_to_new(char *new, char *value, char *path)
{
  int	i;

  i = 0;
  while (path && path[i] != 0)
    {
      new[i] = path[i];
      ++i;
    }
  new[i] = '/';
  i = 0;
  while (value && value[i] != 0)
    {
      new[my_strlen(path) + i + 1] = value[i];
      ++i;
    }
  new[my_strlen(path) + i + 1] = 0;
}

char	*my_path(char *str)
{
  char	*ret;
  int	i;
  int	len;

  i = 0;
  len = my_strlen(str);
  if ((ret = malloc((len + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (i < len)
    {
      ret[i] = str[i];
      ++i;
    }
  ret[i] = 0;
  return (ret);
}

char	**get_path(char **env)
{
  char	*path;
  char	**ret;
  int	i;

  i = 0;
  while (env && env[i] != NULL && !my_strncmp(env[i], "PATH=", 5))
    ++i;
  if (env && env[i] != NULL)
    {
      path = my_path(env[i]);
      ret = str_to_wordtab(&path[5], ':');
      free(path);
      return (ret);
    }
  else
    return (NULL);
}

int	get_access(char **value, char  **env)
{
  char	*new;
  int	i;
  char	**path;

  path = get_path(env);
  i = 0;
  new = value[0];
  while (path && path[i] != NULL && new && access(new, X_OK) == -1)
    {
      if ((new = malloc((my_strlen(value[0]) + my_strlen(path[i]) + 2) *
			sizeof(char))) == NULL)
	return (put_msg_int(2, "Error: cannot perform malloc\n", 0));
      copy_to_new(new, value[0], path[i]);
      if (access(new, X_OK) == 0)
	{
	  free(value[0]);
	  value[0] = new;
	}
      ++i;
    }
  free_tab(path);
  return (1);
}
