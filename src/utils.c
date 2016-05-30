/*
** utils.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Fri May 22 01:27:58 2015 Kévin Empociello
** Last update Sun May 31 15:36:05 2015 Florian Saurs
*/

#include "edit.h"

void		print_tab(char **path)
{
  int		i;

  i = 0;
  while (path && path[i] != NULL)
    {
      printf("TAB [%d] : [%s]\n", i, path[i]);
      i++;
    }
}

double		my_sqrt(double nb, int dec)
{
  double	ret;
  int		i;

  ret = ((nb < 0) ? ((double)-1) : ((double)2));
  i = 0;
  if (ret > 0)
    while (i < dec)
      {
	ret = ((nb - ret * ret) / (2 * ret)) + ret;
	++i;
      }
  return (ret);
}

char		*cpy(char *str)
{
  char		*new;
  int		i;
  int		j;

  i = 5;
  j = 0;
  if ((new = malloc((strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  if (str == NULL)
    return (NULL);
  while (str && str[i] != '\0')
    new[j++] = str[i++];
  new[j] = '\0';
  return (new);
}
