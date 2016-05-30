/*
** str_to_wordtab.c for  in /home/barrie_j/Documents/rendu/Sem_2/PSU/PSU_2014_42sh/RedBlackTree
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Fri May 22 06:26:11 2015 Jean BARRIERE
** Last update Sun May 24 05:25:49 2015 Florian Saurs
*/

#include "types.h"

char	*my_copy_line(char *str, int *start, char delim)
{
  char	*ret;
  int	i;
  int	len;

  i = 0;
  len = 0;
  while (str && str[*start] != 0 && str[*start] == delim)
    ++*start;
  while (str && str[*start + len] != 0 && str[*start + len] != delim)
    ++len;
  if ((ret = malloc((len + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (i < len)
    {
      ret[i] = str[*start + i];
      ++i;
    }
  ret[i] = 0;
  *start = *start + len;
  return (ret);

}

int	my_words(char *str, char delim)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (str && str[i] != 0)
    {
      if (str[i] == delim && str[i + 1] != delim && str[i + 1] != 0)
	++ret;
      ++i;
    }
  if (i > 0)
    ++ret;
  return (ret);
}

char	**str_to_wordtab(char *str, char delim)
{
  char	**ret;
  int	words;
  int	i;
  int	act;

  i = 0;
  act = 0;
  words = my_words(str, delim);
  if ((ret = malloc((words + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (act < words)
    {
      ret[act] = my_copy_line(str, &i, delim);
      ++act;
    }
  ret[act] = NULL;
  return (ret);
}
