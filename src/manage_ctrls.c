/*
** manage_ctrls.c for manage_ctrls in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May  4 11:21:50 2015 guillaume wilmot
** Last update Sun May 24 03:26:40 2015 guillaume wilmot
*/

#include "edit.h"

int		ctrl_e(t_edit **edit, UNUSED t_cmd *cmd)
{
  t_edit	*tmp;

  if ((tmp = *edit) == NULL)
    return (-1);
  while (tmp != NULL && tmp->actual != 1)
    tmp = tmp->prev;
  while (tmp->next != NULL)
    {
      tmp->actual = 0;
      tmp = tmp->next;
    }
  (*edit)->actual = 1;
  return (0);
}

int		ctrl_a(t_edit **edit, UNUSED t_cmd *cmd)
{
  t_edit	*tmp;

  if ((tmp = *edit) == NULL)
    return (-1);
  while (tmp != NULL && tmp->actual != 1)
    tmp = tmp->prev;
  while (tmp->prev != NULL)
    {
      tmp->actual = 0;
      tmp = tmp->prev;
    }
  tmp->actual = 1;
  return (0);
}

int		ctrl_y(t_edit **edit, t_cmd *cmd)
{
  int		i;
  t_edit	*tmp;
  char		buf[2];

  if ((tmp = *edit) == NULL || cmd->clip == NULL)
    return (-1);
  while (tmp != NULL && tmp->actual != 1)
    tmp = tmp->prev;
  i = 0;
  buf[1] = '\0';
  while (cmd->clip[i])
    {
      buf[0] = cmd->clip[i];
      my_put_in_s_edit(edit, buf);
      i++;
    }
  return (0);
}

int	*get_ctrls()
{
  int	*ctrls;

  if ((ctrls = malloc(7 * sizeof(int))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  ctrls[0] = 1;
  ctrls[1] = 292571;
  ctrls[2] = 5;
  ctrls[3] = 11;
  ctrls[4] = 20;
  ctrls[5] = 21;
  ctrls[6] = 25;
  return (ctrls);
}

void	manage_ctrls_and_specials(t_edit **edit, t_cmd *cmd, t_hist **hist)
{
  int	i;
  int	(*fptr[7])(t_edit **edit, t_cmd *cmd);
  int	*ctrls;

  i = 0;
  fptr[0] = &ctrl_a;
  fptr[1] = &ctrl_e;
  fptr[2] = &ctrl_e;
  fptr[3] = &ctrl_k;
  fptr[4] = &ctrl_t;
  fptr[5] = &ctrl_u;
  fptr[6] = &ctrl_y;
  ctrls = get_ctrls();
  if (ctrls != NULL)
    {
      while (i < 7)
	{
	  if (ctrls[i] == cmd->buf_nbr)
	    fptr[i](edit, cmd);
	  i++;
	}
    }
  free(ctrls);
  manage_specials(edit, cmd, hist);
}
