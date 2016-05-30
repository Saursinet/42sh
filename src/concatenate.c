/*
** concatenate.c for concatenate in /home/wilmot_g/my_select
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri Jan  9 17:14:48 2015 guillaume wilmot
** Last update Mon May 11 10:09:27 2015 guillaume wilmot
*/

#include "edit.h"

char	*concatenate(char *str1, char *str2, char separator)
{
  char	*result;
  int	i;
  int	a;

  if (str1 == NULL && str2 == NULL)
    return (NULL);
  if (str1 == NULL || str2 == NULL)
    return ((str1 == NULL) ? my_strdup(str2) : my_strdup(str1));
  i = 0;
  a = 0;
  if ((result = malloc((my_strlen(str1) + my_strlen(str2) + 2) *
		       sizeof(char))) == NULL)
    return (my_errors("\nMalloc : error\n", NULL));
  while (str1[i])
    result[a++] = str1[i++];
  if (separator != 0)
    result[a++] = separator;
  i = 0;
  while (str2[i])
    result[a++] = str2[i++];
  result[a] = '\0';
  return (result);
}
