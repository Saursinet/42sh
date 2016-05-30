/*
** errors_edit.c for errors_edit in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu Apr 30 14:42:01 2015 guillaume wilmot
** Last update Thu Apr 30 18:12:11 2015 guillaume wilmot
*/

#include "edit.h"

void	*my_errors(char *str, void *value)
{
  write(2, str, my_strlen(str));
  return (value);
}

int	my_int_errors(char *str, int value)
{
  write(2, str, my_strlen(str));
  return (value);
}
