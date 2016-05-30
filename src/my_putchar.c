/*
** my_putchar.c for my_putchar in /home/wilmot_g/rendu/Piscine_C_J06
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon Oct  6 09:39:52 2014 guillaume wilmot
** Last update Thu Apr 30 15:24:24 2015 guillaume wilmot
*/

#include "edit.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
