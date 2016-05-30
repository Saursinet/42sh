/*
** put_42shrc.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/42sh
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sat May 23 18:10:13 2015 Florian Saurs
** Last update Fri May 29 23:56:53 2015 Florian Saurs
*/

#include "minishell.h"

void	put(char c, int fd)
{
  write(fd, &c, 1);
}

void	putstr(char *str, int fd)
{
  int	i;

  i = 0;
  while (str[i])
    put(str[i++], fd);
}

void	put_alias(int fd)
{
  putstr("#alias emacs='emacs -nw'\n", fd);
  putstr("#alias ne='emacs -nw'\n", fd);
  putstr("#alias ll='ls -l'\n", fd);
  putstr("#alias la='ls -la'\n", fd);
  putstr("#alias ls='ls --color'\n", fd);
  putstr("#alias grep='grep --color'\n", fd);
  printf("We created you a .42shrc if you want to ");
  printf("to uncomment some alias or add yours you can.\n");
}

int		is_alias(char *str)
{
  int		j;
  static int	i = 0;

  j = 0;
  if (my_strncmp("alias ", str, 5) != 0)
    return (-1);
  while (str[j] != 0 && str[j] != '=' && str[j + 1] != '\'' && str[j] != '\n')
    ++j;
  if ((str[j] == 0 || str[j] == '\n' || str[j - 1] == ' ') && i != 1)
    {
      ++i;
      printf("There is a wrong alias in .42shrc: %s\n", str);
      printf("The presentation is: alias [NAME]=\'[REPLACE]\'\n");
      return (-2);
    }
  if (i == 1)
    return (-2);
  return (0);
}

int	is_export(char *str)
{
  int	j;

  j = 0;
  if (my_strncmp("export ", str, 6) != 0)
    return (-1);
  while (str[j] != 0 && str[j] != '=' && str[j] != '\n')
    ++j;
  if (str[j] == 0 || str[j] == '\n' || str[j - 1] == ' ')
    {
      printf("There is a wrong export in .42shrc: %s\n", str);
      printf("The presentation is: export [NAME]=[VALUE]\n");
      return (-1);
    }
  return (0);
}
