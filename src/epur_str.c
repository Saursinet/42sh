/*
** epur_str.c for  in /home/barrie_j/Documents/Sem_2/PSU_2014_42sh/RedBlackTree
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Thu Apr 23 16:36:15 2015 Jean BARRIERE
** Last update Sun May  3 21:36:07 2015 Jean BARRIERE
*/

#include "types.h"

static int	get_count(char *str)
{
  int		i;
  int		len;
  int		count;

  len = my_strlen(str);
  count = 0;
  i = -1;
  while (++i < len)
    {
      while ((str[i] == ' ' || str[i] == '\t') &&
	     (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == 0))
	++i;
      if (count == 0 && str[i] == ' ')
	++i;
      else
	++count;
    }
  return (count);
}

static void	set_new(char *str, char *new)
{
  int		j;
  int		i;
  int		len;

  j = 0;
  i = -1;
  len = my_strlen(str);
  while (++i < len)
    {
      while ((str[i] == ' ' || str[i] == '\t') &&
	     (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == 0))
	++i;
      if (j == 0 && str[i] == ' ')
	++i;
      if (i < len && str[i] == '\t')
	new[j] = ' ';
      else if (i < len)
	new[j] = str[i];
      if (i < len)
	++j;
    }
  new[j] = 0;
}

char	*epur_str(char *str, int flag)
{
  char	*new;
  int	count;

  count = get_count(str);
  if ((new = malloc((count + 2) * sizeof(char))) == NULL)
    return (put_msg_ptr(2, ERR_MALLOC, NULL));
  set_new(str, new);
  if (flag == 1)
    free(str);
  return (new);
}
