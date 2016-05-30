/*
** my_pow.c for my_pow in /home/wilmot_g/minishell2/Lib
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun Mar  8 18:55:55 2015 guillaume wilmot
** Last update Tue May 19 12:31:27 2015 guillaume wilmot
*/

#include "edit.h"

int	my_pow(int nbr, int pow)
{
  int   i;

  if (pow == 0)
    return (1);
  i = 1;
  while (i++ < pow)
    nbr *= nbr;
  return (nbr);
}
