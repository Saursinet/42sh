/*
** free_array.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Fri May 22 01:33:06 2015 Kévin Empociello
** Last update Sun May 24 02:28:58 2015 guillaume wilmot
*/

#include "edit.h"

void	free_array(int **matrix)
{
  int	y;

  y = 0;
  while (matrix && matrix[y] != NULL)
    {
      free(matrix[y]);
      y++;
    }
  if (matrix)
    free(matrix);
}

void	free_array_char(char **matrix)
{
  int	y;

  y = 0;
  while (matrix && matrix[y] != NULL)
    {
      free(matrix[y]);
      y++;
    }
  if (matrix)
    free(matrix);
}
