/*
** on_verra.c for minshell in /home/saurs_f/rendu/PSU_2014_minishell1
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Jan 26 23:43:29 2015 Florian Saurs
** Last update Sun May 24 14:58:35 2015 Florian Saurs
*/

#include "minishell.h"

void	free_my_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    free(env[i++]);
  free(env);
}

char	*take_it(char **env, char *my_path, char *pwd)
{
  int	c;
  int	i;
  int	j;
  int	len;

  c = 7;
  i = 0;
  while (env[i] != NULL && my_strncmp("OLDPWD=", env[i], 6) != 0)
    ++i;
  if (env[i] == NULL)
    return (NULL);
  else
    {
      j = 0;
      if (pwd != NULL)
	len = my_strlen(env[i]) + my_strlen(pwd);
      else
	len = my_strlen(env[i]);
      if ((my_path = malloc((sizeof(char)) * len)) == NULL)
	return (NULL);
      while (env[i][c] != 0)
	my_path[j++] = env[i][c++];
      my_path[j] = 0;
    }
  return (my_path);
}

char	*take_pwd(char **env)
{
  int	j;
  int	i;
  char	*pwd;
  char	*my_pwd;

  j = 0;
  while (env[j] != NULL && my_strncmp("PWD=", env[j], 3) != 0)
    ++j;
  pwd = env[j];
  j = 0;
  if (pwd != NULL)
    {
      if ((my_pwd = malloc(sizeof(char) * my_strlen(pwd))) == NULL)
	return (NULL);
      while (pwd[j++] != '=');
      i = 0;
      while (pwd[j] != 0)
	my_pwd[i++] = pwd[j++];
      my_pwd[i] = 0;
      return (my_pwd);
    }
  return (pwd);
}
