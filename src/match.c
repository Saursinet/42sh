/*
** match.c for match in /home/wilmot_g/my_select
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Dec 30 15:55:11 2014 guillaume wilmot
** Last update Mon May 11 23:05:41 2015 guillaume wilmot
*/

#include "edit.h"

int	hidden_match(char *str1, char *str2)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  while (str1[i])
    {
      j = i;
      k = 0;
      while (str1[j] && str2[k] && str2[k] == str1[j])
	{
	  j++;
	  k++;
	}
      if (k == my_strlen(str2))
	return (1);
      i++;
    }
  return (0);
}

int	beggin_match(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i])
    i++;
  if (i == my_strlen(str2))
    return (1);
  return (0);
}

int	match(char *str1, char *str2)
{
  int	i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  i = 0;
  if (my_strlen(str1) == my_strlen(str2))
    {
      while (str1[i] && str2[i])
	{
	  if (str1[i] == str2[i])
	    i = i + 1;
	  else
	    return (0);
	}
      return (1);
    }
  else
    return (0);
}
