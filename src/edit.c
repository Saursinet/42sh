/*
** edit.c for edit in /home/wilmot_g/LOLOL/Edit
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu Mar  5 18:07:17 2015 guillaume wilmot
** Last update Sun May 31 19:03:09 2015 guillaume wilmot
*/

#include "edit.h"

int		delete_actual(t_edit *edit, int i)
{
  t_edit	*ptr_temp;

  if (edit == NULL)
    return (0);
  ptr_temp = edit;
  while (ptr_temp->prev != NULL && ptr_temp->actual != 1)
    ptr_temp = ptr_temp->prev;
  if (i == 0)
    {
      if (ptr_temp->prev != NULL)
	my_remove_s_edit_link(ptr_temp->prev);
    }
  else if (i == 1)
    if (ptr_temp != NULL && ptr_temp->next != NULL && ptr_temp != edit)
      my_suppr_s_edit_link(ptr_temp);
  return (0);
}

void		move_cursor(t_edit **edit, int nbr, t_hist **hist)
{
  if (nbr == 284379 || nbr == 280283 || nbr == 4405 || nbr == 4341)
    move_actual(edit, nbr);
  else if ((nbr == 272091 || nbr == 276187) && *hist != NULL)
    {
      if (nbr == 272091 || nbr == 276187)
	if (((nbr == 276187) ? (*hist)->prev : (*hist)->next) != NULL)
	  {
	    *hist = ((nbr == 276187) ? (*hist)->prev : (*hist)->next);
	    if ((*hist)->edit != NULL)
	      {
		my_edit_free(*edit);
		*edit = my_edit_dup((*hist)->edit);
	      }
	  }
    }
}

int		init_edit(t_edit **edit, t_cmd *cmd, char *term, char *too_much)
{
  *edit = NULL;
  if (isatty(0))
    if (prompt(save_my_env(NULL)) == -1)
      return (-1);
  if ((cmd->pos = get_position(term)) == NULL)
    return (my_int_errors("Tgetstr : error\n", -1));
  if ((cmd->buf = malloc(5 * sizeof(char))) == NULL)
    return (my_int_errors("Malloc : error\n", -1));
  my_put_in_s_edit(edit, " ");
  if (too_much != NULL)
    {
      is_too_much(1);
      put_too_much(edit, &too_much);
    }
  my_show_s_edit(*edit, term);
  set_visibility_cursor(term, 0);
  if (set_canon(1) == -1)
    return (-1);
  cmd->buf_nbr = 0;
  cmd->clip = NULL;
  return (0);
}

void		choose_edit(t_edit **edit, int *stop, t_cmd *cmd, t_hist **hist)
{
  int	nbr;

  nbr = cmd->buf_nbr;
  if (nbr == 284379 || nbr == 280283 || nbr == 4405 || nbr == 4341 ||
      nbr == 272091 || nbr == 276187)
    move_cursor(edit, nbr, hist);
  else if (nbr == 127)
    delete_actual(*edit, 0);
  else if (nbr == 4 || nbr == 10)
    cmd->cmd = take_cmd(*edit, nbr, stop);
  else if (nbr != 8 && nbr != 990062299 && nbr != 4213 && nbr != 4277 && nbr !=
	   300763 && nbr != 292571 && nbr != 1 && nbr != 5 && nbr != 11 && nbr
	   != 12 && nbr != 20 && nbr != 21 && nbr != 25 && nbr != 2114152155 &&
	   nbr != 2114156251 && nbr != 4341 && nbr != 4405 && nbr != 2114143963
	   && nbr != 9 && nbr != -417822 && nbr != -413726 && nbr != -458398 &&
	   nbr != -454302 && -466590 && nbr != -5755 && nbr != -352158 &&
	   nbr != -466590 && nbr != 374491 && nbr != 6363)
    my_put_in_s_edit(edit, cmd->buf);
}

char		*get_cmd(t_hist **hist, char *term, int *stop, char **paths)
{
  t_edit	*edit;
  t_cmd		cmd;
  int		i;
  static char	*too_much = NULL;

  if ((cmd.cmd = init_too_much(&too_much, stop)) != NULL)
    return (cmd.cmd);
  if (init_edit(&edit, &cmd, term, too_much) == -1)
    return (my_errors("\n", NULL));
  while (cmd.buf_nbr != 10 && cmd.buf_nbr != 4 &&
	 (cmd.ret = read(0, cmd.buf, 4)) != -1)
    {
      global_edit(&cmd, &edit, stop, hist);
      if ((i = auto_comp(&edit, &cmd, paths, 0)) >= 1)
	if (reset_pos(term, &cmd.pos, edit, i) == NULL)
	  return (my_errors("\n", NULL));
      if (cmd.buf_nbr == 12)
	return (my_clear(term));
      if (manage_too_much(edit))
	return (set_too_much(&too_much, edit, &cmd.buf_nbr, cmd.pos));
    }
  return (end_edit(&too_much, &cmd, edit, hist));
}
