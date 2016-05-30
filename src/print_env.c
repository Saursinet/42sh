/*
** print_env.c for minishell in /home/saurs_f/rendu/PSU_2014_minishell1
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Jan 27 14:26:22 2015 Florian Saurs
** Last update Sun May 24 14:57:44 2015 Florian Saurs
*/

#include "minishell.h"

int	print_env(char **env)
{
  int	i;

  i = 0;
  env = save_my_env(NULL);
  while (env[i] != NULL)
    printf("%s\n", env[i++]);
  return (0);
}

char	**past_my_env(char **env)
{
  char	**my_env;
  int	i;
  int	c;

  i = 0;
  while (env[i++] != NULL);
  if ((my_env = malloc(i * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (env[i] != NULL)
    {
      c = 0;
      if ((my_env[i] = malloc((1 + my_strlen(env[i])) * sizeof(char))) == NULL)
	return (NULL);
      while (env[i][c] != 0)
	{
	  my_env[i][c] = env[i][c];
	  ++c;
	}
      my_env[i++][c] = 0;
    }
  my_env[i] = NULL;
  return (my_env);
}
