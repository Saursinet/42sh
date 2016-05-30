/*
** unsetenv.c for minishell in /home/saurs_f/rendu/PSU_2014_minishell1
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Jan 27 00:13:00 2015 Florian Saurs
** Last update Sun May 24 18:17:39 2015 Florian Saurs
*/

#include "minishell.h"

int	check(char **env, char *name)
{
  int	i;
  int	length;

  i = 0;
  while (env[i] != NULL)
    {
      length = my_strlen(name) - 1;
      if (my_strncmp(env[i], name, length) == 0)
	return (1);
      ++i;
    }
  return (0);
}

int	my_unsetenv(char **env, char *name)
{
  int	i;
  int	length;

  i = 0;
  if (check(env, name) == 0)
    return (-1);
  length = my_strlen(name) - 1;
  while (env[i] && my_strncmp(env[i], name, length) != 0)
    ++i;
  free(env[i]);
  while (env[i + 1] != NULL)
    {
      env[i] = env[i + 1];
      ++i;
    }
  env[i] = NULL;
  env = save_my_env(env);
  return (0);
}
