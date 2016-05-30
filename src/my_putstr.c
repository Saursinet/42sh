/*
** my_putstr.c for my_putstr in /home/wilmot_g/rendu/Piscine_C_J06
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon Oct  6 09:38:22 2014 guillaume wilmot
** Last update Thu Apr 30 15:25:41 2015 guillaume wilmot
*/

#include "edit.h"

void	my_putstr(char *str)
{
  int	i;

  if (str != NULL)
    {
      i = 0;
      while (str[i] != '\0')
	{
	  my_putchar(str[i]);
	  i = i + 1;
	}
    }
}
