/*
** try_change.c for minishell2 in /home/saursf/rendu/PSU_2014_minishell2
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Fri Mar  6 18:37:46 2015 Florian Saurs
** Last update Sun May 31 16:24:35 2015 Florian Saurs
*/

#include "minishell.h"

int	check_access(char *my_path)
{
  if (access(my_path, 0) == -1)
    {
      printf("%s : No such file or directory.\n", my_path);
      return (-1);
    }
  if (chdir(my_path) == -1)
    {
      printf("%s : Not a directory.\n", my_path);
      return (-1);
    }
  return (0);
}

char	*check_this_var(char *my_path, char *pwd)
{
  int	i;
  int	c;

  if (my_path[0] != '/')
    if (pwd != NULL)
      my_path = my_strcat(pwd, my_path);
  i = 0;
  while (my_path[i] != 0 && my_path[i++] != '.');
  if (my_path[i] == '.')
    {
      c = i + 1;
      while (i != 0 && my_path[i--] != '/');
      if (my_path[i + 1] == '/')
	while (i != 0 && my_path[i--] != '/');
      ++i;
      while (my_path[c] != 0)
	my_path[i++] = my_path[c++];
      my_path[i] = 0;
      my_path = check_this_var(my_path, pwd);
    }
  return (my_path);
}

char	*my_tild(char *my_path, char **env, int i)
{
  int	j;
  int	length;
  char	*new_path;

  i = 0;
  while (env[i] != NULL && my_strncmp(env[i], "HOME=", 4) != 0)
    ++i;
  if (env[i] != NULL)
    {
      length = my_strlen(env[i]) + my_strlen(my_path) - 4;
      if ((new_path = malloc(length * sizeof(char))) == NULL)
	return (NULL);
      length = 5;
      j = 0;
      while (env[i][length] != 0)
	new_path[j++] = env[i][length++];
      length = 1;
      while (my_path && my_path[length] != 0)
	new_path[j++] = my_path[length++];
      new_path[j] = 0;
      return (new_path);
    }
  return (my_path);
}

void	change_my_env(char *pwd, char *my_path, char **env)
{
  if (pwd != NULL)
    my_setenv(env, "OLDPWD", pwd);
  my_path = check_this_var(my_path, pwd);
  my_setenv(env, "PWD", my_path);
}

int	change_directory(char *my_path, char **env)
{
  int	i;
  char	*pwd;

  i = 3;
  pwd = take_pwd(env);
  if (my_path == NULL)
    my_path = my_tild(my_path, env, i);
  if (my_path && my_path[0] == '~')
    my_path = my_tild(my_path, env, i);
  if (my_path && my_path[0] == '-' && my_path[1] == 0)
    if ((my_path = take_it(env, my_path, pwd)) == NULL)
      return (-1);
  if (my_path == NULL)
    {
      printf("cd failed\n");
      return (-1);
    }
  if (check_access(my_path) == -1)
    return (-1);
  change_my_env(pwd, my_path, env);
  return (0);
}
