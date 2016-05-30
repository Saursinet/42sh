/*
** my_atoi.c for my_atoi in /home/wilmot_g/tempoJ011/lib/my
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun Nov  9 19:55:03 2014 guillaume wilmot
** Last update Sun May 24 15:52:49 2015 Florian Saurs
*/

#include "edit.h"

int	my_atoi(char *str)
{
  int	i;
  int	number;
  int	neg;

  if (str == NULL)
    return (0);
  i = 0;
  number = 0;
  if (!(str))
    return (0);
  neg = 0;
  if (str[0] == '-')
    {
      i = 1;
      neg = 1;
    }
  while (str[i] >= 48 && str[i] <= 57)
    {
      number *= 10;
      number += ((int)str[i] - 48);
      i++;
    }
  if (neg == 1)
    number = -number;
  return (number);
}

void	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb == -2147483648)
    write(1, "-2147483648", 11);
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = -nb;
	}
      while ((nb / i) > 9)
	i = i * 10;
      while (i > 0)
	{
	  my_putchar(48 + ((nb / i) % 10));
	  i /= 10;
	}
    }
}
