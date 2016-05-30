/*
** my_strdup.c for my_strdup in /home/wilmot_g/Projets/PSU_2014_my_printf
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun Nov 30 21:23:00 2014 guillaume wilmot
** Last update Thu Apr 30 19:06:36 2015 guillaume wilmot
*/

#include "edit.h"

char	*my_strdup(char *str)
{
  char	*dest;

  if (str == NULL)
    return (NULL);
  if ((dest = malloc((my_strlen(str) + 1) * sizeof(char *))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  my_strcpy(dest, str);
  dest[my_strlen(str)] = '\0';
  return (dest);
}
