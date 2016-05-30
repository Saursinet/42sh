/*
** my_realloc.c for my_realloc in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 11 22:51:11 2015 guillaume wilmot
** Last update Tue May 12 14:43:23 2015 guillaume wilmot
*/

#include "edit.h"

char	**my_realloc_double_tab(char **str, int len)
{
  char	**new;
  int	i;

  i = 0;
  if ((new = malloc((len + 3) * sizeof(char *))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (i < len)
    {
      new[i] = my_strdup(str[i]);
      free(str[i]);
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}
