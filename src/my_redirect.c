/*
** my_redirect.c for minishell1 in /home/saursf/rendu/PSU_2014_minishell2
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Feb 16 11:17:46 2015 Florian Saurs
** Last update Sun May 31 02:44:16 2015 guillaume wilmot
*/

#include "minishell.h"

void	rig_s(char **s, int i)
{
  int   fd;

  if (s[i + 2])
    {
      if ((fd = open(s[i + 2], O_RDWR | O_TRUNC | O_CREAT, 0666)) == -1)
	my_errors("Open : error\n", NULL);
      if (dup2(fd, 1) == -1)
	my_errors("Dup2 : error\n", NULL);
    }
  else
    my_errors("No file to open!\n", NULL);
}

void	rig_d(char **s, int i)
{
  int   fd;

  if (s[i + 2])
    {
      if ((fd = open(s[i + 2], O_RDWR | O_APPEND | O_CREAT, 0666)) == -1)
	my_errors("Open : error\n", NULL);
      if (dup2(fd, 1) == -1)
	my_errors("Dup2 : error\n", NULL);
    }
  else
    my_errors("No file to open!\n", NULL);
}

void	left_simple(char **arg, int i)
{
  int	fd;

  if (arg[i + 2] && access(arg[i + 2], 0) == -1)
      printf("No such file or directory: %s\n", arg[i + 2]);
  else
    {
      if ((fd = open(arg[i + 2], O_RDONLY)) == -1)
	my_errors("Open : error\n", NULL);
      if (dup2(fd, 0) == -1)
	my_errors("Dup2 : error\n", NULL);
    }
}
