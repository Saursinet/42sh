/*
** edit_loop.c for edit_loop in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 22 07:22:44 2015 guillaume wilmot
** Last update Sun May 24 21:52:03 2015 guillaume wilmot
*/

#include "edit.h"

char	*end_edit(char **too_much, t_cmd *cmd, t_edit *edit, t_hist **hist)
{
  *too_much = NULL;
  if (cmd->ret == -1)
    return (set_position(cmd->pos, get_term(NULL)));
  return (end_acquisition(hist, edit, get_term(NULL), cmd));
}

void	play_with_cmd(t_cmd *cmd)
{
  cmd->i = 0;
  cmd->buf[cmd->ret] = '\0';
  cmd->buf_nbr = 0;
  while (cmd->buf[cmd->i++])
    cmd->buf_nbr += cmd->buf[cmd->i - 1] *
      ((cmd->i == 1) ? cmd->i : my_pow(8, cmd->i));
}

void	global_edit(t_cmd *cmd, t_edit **edit, int *stop, t_hist **hist)
{
  play_with_cmd(cmd);
  choose_edit(edit, stop, cmd, hist);
  manage_ctrls_and_specials(edit, cmd, hist);
  separate_strings(edit);
  set_position(cmd->pos, get_term(NULL));
  my_show_s_edit(*edit, get_term(NULL));
}

char	*init_too_much(char **too_much, int *stop)
{
  char	*str;

  if (!isatty(0) && ((str = get_next_line(0)) != NULL))
    return (str);
  else if (!isatty(0))
    {
      *stop = 1;
      return (my_strdup(""));
    }
  if (check_for_char(*too_much, '\n'))
    {
      is_too_much(1);
      return (update_too_much(too_much));
    }
  return (NULL);
}
