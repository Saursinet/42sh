/*
** distance.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Fri May 22 15:21:51 2015 Kévin Empociello
** Last update Sun May 24 02:24:01 2015 guillaume wilmot
*/

#include "edit.h"

int	give_min(int a, int b, int c)
{
  int	check;

  check = 0;
  if (a <= b && a <= c)
    check = a;
  else if (b <= a && b <= c)
    check = b;
  else if (c <= a && c <= b)
    check = c;
  return (check);
}

int	give_distance(char *str1, char *str2)
{
  int	i;
  int	k;
  int	**m;
  int	ct;

  if (((i = 1) == 1) && ((k = 0) == 0))
    ct = 0;
  m = new_matrix(strlen(str1), strlen(str2), (m = NULL));
  while (i <= my_strlen(str2))
    {
      k = 1;
      while (k <= my_strlen(str1))
	{
	  if (str1[k - 1] == str2[i - 1])
	    ct = 0;
	  else
	    ct = 1;
	  m[k][i] = give_min(m[k][i - 1] + 1, m[k - 1][i] + 1, m[k - 1][i - 1] + ct);
	  k++;
	}
      i++;
    }
  ct = m[strlen(str1)][strlen(str2)];
  free_array(m);
  return (ct);
}
