/*
** specials.c for specials in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue May  5 15:27:41 2015 guillaume wilmot
** Last update Thu May 14 01:21:25 2015 guillaume wilmot
*/

#include "edit.h"

int		ctrl_right(t_edit **edit, UNUSED t_hist **hist)
{
  t_edit        *tmp;
  int		key;
  int		i;

  key = 0;
  i = 0;
  if ((tmp = *edit) == NULL)
    return (-1);
  while (tmp != NULL && tmp->actual != 1)
    tmp = tmp->prev;
  while (tmp->next != NULL && key != 1)
    {
      if (tmp->next->c[0] == ' ' && i != 0)
	key = 1;
      i++;
      tmp->actual = 0;
      tmp = tmp->next;
    }
  tmp->actual = 1;
  return (0);
}

int		ctrl_left(t_edit **edit, UNUSED t_hist **hist)
{
  t_edit        *tmp;
  int		key;
  int		i;

  key = 0;
  i = 0;
  if ((tmp = *edit) == NULL)
    return (-1);
  while (tmp != NULL && tmp->actual != 1)
    tmp = tmp->prev;
  while (tmp->prev != NULL && key != 1)
    {
      if (tmp->prev->prev != NULL)
	if (tmp->prev->prev->c[0] == ' ' && i != 0)
	  key = 1;
      i++;
      tmp->actual = 0;
      tmp = tmp->prev;
    }
  tmp->actual = 1;
  return (0);
}

int		hist_top(t_edit **edit, t_hist **hist)
{
  t_hist	*tmp_h;
  char		*tmp;
  char		*to_find;

  if (*hist == NULL || (*hist)->next == NULL)
    return (0);
  tmp_h = (*hist)->next;
  to_find = take_cmd_until(*edit);
  tmp = take_cmd(tmp_h->edit, 0, 0);
  while (tmp_h->next != NULL && !hidden_match(tmp, to_find))
    {
      tmp_h = tmp_h->next;
      my_free(tmp);
      tmp = take_cmd(tmp_h->edit, 0, 0);
    }
  if (hidden_match(tmp, to_find))
    {
      my_edit_free(*edit);
      *hist = tmp_h;
      *edit = my_edit_dup((*hist)->edit);
    }
  my_free(tmp);
  my_free(to_find);
  return (0);
}

int		hist_bottom(t_edit **edit, t_hist **hist)
{
  t_hist	*tmp_h;
  char		*tmp;
  char		*to_find;

  if (*hist == NULL || (*hist)->prev == NULL)
    return (0);
  tmp_h = (*hist)->prev;
  to_find = take_cmd_until(*edit);
  tmp = take_cmd(tmp_h->edit, 0, 0);
  while (tmp_h->prev != NULL && !hidden_match(tmp, to_find))
    {
      tmp_h = tmp_h->prev;
      my_free(tmp);
      tmp = take_cmd(tmp_h->edit, 0, 0);
    }
  if (hidden_match(tmp, to_find))
    {
      my_edit_free(*edit);
      *hist = tmp_h;
      *edit = my_edit_dup((*hist)->edit);
    }
  my_free(tmp);
  my_free(to_find);
  return (0);
}

int	spe_suppr(t_edit **edit, UNUSED t_hist **hist)
{
  delete_actual(*edit, 1);
  return (0);
}
