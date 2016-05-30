/*
** matrix.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Fri May 22 01:30:05 2015 Kévin Empociello
** Last update Sun May 24 21:44:29 2015 Florian Saurs
*/

#include "edit.h"

void	display_matrix(int **matrix)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (matrix[y] != NULL)
    {
      x = 0;
      while (matrix[y][x] != -1)
	{
	  my_put_nbr(matrix[y][x]);
	  x++;
	}
      my_putchar('\n');
      y++;
    }
}

int	**fill_matrix(int **matrix)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (matrix && matrix[y] != NULL && matrix[y][x] != -1)
    {
      matrix[y][x] = x;
      x++;
    }
  x = 0;
  while (matrix && matrix[y] != NULL && matrix[y][x] != -1)
    {
      matrix[y][x] = y;
      y++;
    }
  return (matrix);
}

int	**new_matrix(int rows, int col, int **matrix)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((matrix = malloc((rows + 2) * sizeof(int *))) == NULL)
    return (NULL);
  while (i <= rows)
    {
      j = 0;
      if ((matrix[i] = malloc((col + 2) * sizeof(int))) == NULL)
	return (NULL);
      while (j <= col)
	matrix[i][j++] = 0;
      matrix[i][j] = -1;
      i++;
    }
  matrix[rows + 1] = NULL;
  matrix = fill_matrix(matrix);
  return (matrix);
}
