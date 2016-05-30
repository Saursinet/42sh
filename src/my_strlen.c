/*
** my_strlen.c for my_strlen in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 23 16:24:21 2015 guillaume wilmot
** Last update Sun May 24 18:47:53 2015 Florian Saurs
*/

#include "edit.h"

int	biggest_in_tab(char **str)
{
  int	i;
  int	biggest;

  i = 0;
  biggest = 0;
  while (str[i])
    {
      biggest = (my_strlen(str[i]) > biggest) ? my_strlen(str[i]) : biggest;
      i++;
    }
  return (biggest);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str && str[i] != '\0')
    ++i;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1 && s2 && s1[i] && s1[i] == s2[i])
    ++i;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  return (s1[i] - s2[i]);
}
