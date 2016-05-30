/*
** too_much.c for too_much in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 18 17:03:05 2015 guillaume wilmot
** Last update Sun May 31 21:16:22 2015 guillaume wilmot
*/

#include "edit.h"

void		put_too_much(t_edit **edit, char **too_much)
{
  char		buf[2];
  int		i;

  i = 0;
  buf[1] = '\0';
  while ((*too_much)[i])
    {
      buf[0] = (*too_much)[i];
      my_put_in_s_edit(edit, buf);
      i++;
    }
  *too_much = NULL;
}

char		*set_too_much(char **too_much, t_edit *edit, int *buf,
			      char *pos)
{
  char		*str;
  char		*new;
  int		i;

  is_too_much(1);
  set_position(pos, get_term(NULL));
 *buf = 4;
  i = 0;
  if ((str = take_cmd(edit, 0, 0)) == NULL)
    return (NULL);
  if ((new = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (str[i] && str[i] != '\n')
    {
      new[i] = str[i];
      i++;
    }
  if (str[i] != '\n')
    return (str);
  new[i] = '\0';
  *too_much = (str[i + 1]) ? &str[i + 1] : NULL;
  return (new);
}

char	*update_too_much(char **too_much)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc((my_strlen(*too_much) + 2) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while ((*too_much)[i] && (*too_much)[i] != '\n')
    {
      new[i] = (*too_much)[i];
      i++;
    }
  if ((*too_much)[i] != '\n')
    {
      free(new);
      *too_much = NULL;
      return (*too_much);
    }
  new[i] = '\0';
  *too_much = &(*too_much)[i + 1];
  return (new);
}

int	manage_too_much(t_edit *edit)
{
  int	ok;
  char	*tmp;

  if ((tmp = take_cmd(edit, 0, 0)) == NULL)
    return (0);
  ok = 0;
  if (check_for_char(tmp, '\n'))
    ok = 1;
  free(tmp);
  return (ok);
}
