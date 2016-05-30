/*
** my_strcpy.c for my_strcpy in /home/wilmot_g/rendu/Piscine_C_J06
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon Oct  6 09:06:34 2014 guillaume wilmot
** Last update Thu Apr 30 15:25:57 2015 guillaume wilmot
*/

#include "edit.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
