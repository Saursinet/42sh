/*
** ctrls.c for ctrls in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May  4 12:45:49 2015 guillaume wilmot
** Last update Sat May 23 16:19:28 2015 guillaume wilmot
*/

#include "edit.h"

int		ctrl_k_end(t_edit **edit)
{
  (*edit)->actual = 1;
  my_put_in_s_edit(edit, " ");
  *edit = (*edit)->prev;
  (*edit)->actual = 1;
  (*edit)->next = NULL;
  return (0);
}

int		ctrl_k(t_edit **edit, t_cmd *cmd)
{
  t_edit	*tmp;
  int		i;
  int		j;

  if ((tmp = *edit) == NULL || (i = 0) != 0)
    return (-1);
  while (tmp != NULL && tmp->actual != 1 && i++ >= 0)
    tmp = tmp->prev;
  if (tmp->next == NULL)
    return (-1);
  if ((cmd->clip = malloc((i + 5) * sizeof(char))) == NULL || (i = 0) != 0)
    return (my_int_errors("Malloc : error\n", -1));
  while (tmp->next != NULL)
    {
      j = 0;
      while (tmp->c[j])
	cmd->clip[i++] = tmp->c[j++];
      tmp = tmp->next;
    }
  cmd->clip[i] = '\0';
  while ((*edit)->prev != NULL && (*edit)->actual != 1)
    *edit = (*edit)->prev;
  return (ctrl_k_end(edit));
}

int		ctrl_u(t_edit **edit, t_cmd *cmd)
{
  int		i;
  int		j;
  t_edit	*tmp;

  if ((tmp = *edit) == NULL)
    return (-1);
  while (tmp != NULL && tmp->actual != 1)
    tmp = tmp->prev;
  if (tmp->prev == NULL)
    return (-1);
  i = 0;
  while (tmp->prev != NULL && i++ >= 0)
    tmp = tmp->prev;
  if ((cmd->clip = malloc((i + 5) * sizeof(char))) == NULL)
    return (my_int_errors("Malloc : error\n", -1));
  i = 0;
  while (tmp->next != NULL && tmp->actual != 1)
    {
      j = 0;
      while (tmp->c[j])
	cmd->clip[i++] = tmp->c[j++];
      tmp = tmp->next;
    }
  tmp->prev = NULL;
  return (0);
}

int		ctrl_t(t_edit **edit, UNUSED t_cmd *cmd)
{
  t_edit	*tmp;
  t_edit	*back;
  t_edit	*back_again;

  if ((tmp = *edit) == NULL)
    return (-1);
  while (tmp != NULL && tmp->actual != 1)
    tmp = tmp->prev;
  if (tmp->prev != NULL)
    if (tmp->prev->prev != NULL)
      {
	back = tmp->prev;
	back_again = back->prev;
	back->next = back_again;
	back->prev = back_again->prev;
	if (back_again->prev != NULL)
	  back_again->prev->next = back;
	back_again->next = tmp;
	back_again->prev = back;
	tmp->prev = back_again;
	tmp->actual = (tmp->next == NULL) ? tmp->actual : 0;
	if (tmp->next != NULL)
	  tmp->next->actual = 1;
      }
  return (0);
}
