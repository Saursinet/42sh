/*
** setenv.c for minishell in /home/saurs_f/rendu/PSU_2014_minishell1
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Jan 26 23:32:57 2015 Florian Saurs
** Last update Fri May 29 15:35:42 2015 Florian Saurs
*/

#include "minishell.h"

int	check_var(char **env, char *name)
{
  int	i;
  int	length;

  i = 0;
  length = my_strlen(name) - 1;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], name, length) == 0)
	return (i);
      ++i;
    }
  return (-1);
}

char	**my_env(char **env, int i)
{
  char	**tmp;
  int	c;

  while (env[i] != NULL)
    ++i;
  if ((tmp = malloc((i + 2) * sizeof(char *))) == NULL)
   return (NULL);
  i = 0;
  while (env[i] != NULL)
    {
      c = my_strlen(env[i]);
      if ((tmp[i] = malloc((c + 1) * sizeof(char))) == NULL)
	return (NULL);
      c = 0;
      while (env[i][c] != 0)
	{
	  tmp[i][c] = env[i][c];
	  ++c;
	}
      free(env[i]);
      tmp[i++][c] = 0;
    }
  tmp[i] = NULL;
  return (tmp);
}

char	**complete_that(char **env, int c, char *name, char *value)
{
  int	i;
  int	j;
  int	length;

  i = 0;
  j = 0;
  length = my_strlen(name) + my_strlen(value);
  if ((env[c] = malloc((length + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (name[i] != 0)
    {
      env[c][i] = name[i];
      ++i;
    }
  env[c][i++] = '=';
  while (value[j] != 0)
    {
      env[c][i] = value[j];
      ++i;
      ++j;
    }
  env[c][i++] = 0;
  return (env);
}

int	my_setenv(char **env, char *name, char *value)
{
  int	c;

  c = 0;
  env = save_my_env(NULL);
  if (check_var(env, name) == -1)
    {
      env = my_env(env, 0);
      while (env && env[c] != NULL)
	++c;
      env = complete_that(env, c++, name, value);
      env[c] = NULL;
    }
  else
    {
      c = check_var(env, name);
      free(env[c]);
      env = complete_that(env, c, name, value);
    }
  if (env == NULL)
    return (-1);
  env = save_my_env(env);
  return (0);
}
