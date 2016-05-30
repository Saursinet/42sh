/*
** exit.c for exit in /home/wilmot_g/.ssh/PSU_2014_42sh/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 24 22:27:18 2015 guillaume wilmot
** Last update Sun May 24 23:20:51 2015 guillaume wilmot
*/

#include "edit.h"

int	check_exit(char **arg, int i, int status)
{
  if (!my_strncmp("exit", arg[i], 3) &&
      ((status == 0 && i > 0 && my_strcmp(arg[i - 1], "&&") == 0) ||
       (status == -1 && i > 0 && my_strcmp(arg[i - 1], "||") == 0) ||
       i == 0 || my_strcmp(arg[i - 1], ";") == 0))
    stop_this(arg, i);
  return (1);
}

int	stop_this(char **arg, int i)
{
  int	j;

  j = 0;
  while (arg[i][j] && arg[i][j] != ' ' && arg[i][j] != '\t')
    j++;
  while (arg[i][j] && (arg[i][j] == ' ' || arg[i][j] == '\t'))
    j++;
  if (arg[i][j])
    get_return_value(atoi(&arg[i][j]), 1, 1, 0);
  else
    get_return_value(0, 1, 1, 0);
  return (0);
}
