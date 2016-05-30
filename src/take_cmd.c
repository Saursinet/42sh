/*
** take_cmd.c for take_cmd in /home/wilmot_g/minishell2
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun Mar  8 19:28:37 2015 guillaume wilmot
** Last update Sun May 24 03:41:58 2015 guillaume wilmot
*/

#include "edit.h"

char		*end_acquisition(t_hist **hist, t_edit *edit,
				char *term, t_cmd *cmd)
{
  char		*prev;

  prev = NULL;
  if ((*hist)->next != NULL)
    prev = take_cmd((*hist)->next->edit, 0, NULL);
  if (cmd->cmd != NULL)
    if (cmd->cmd[0] != '\0')
      if (!match(cmd->cmd, prev))
	my_put_in_s_hist(hist, my_edit_dup(edit));
  my_edit_free(edit);
  set_visibility_cursor(term, 1);
  set_position(cmd->pos, term);
  free(cmd->buf);
  set_canon(0);
  free(prev);
  return (cmd->cmd);
}

char		*str_null(int *ret)
{
  *ret = 1;
  return (NULL);
}

char		*take_cmd(t_edit *edit, int nbr, int *ret)
{
  t_edit        *tmp;
  char          *cmd;
  int           j;
  int		i;

  tmp = ((i = 3) == 4) ? edit : edit;
  while (tmp->prev != NULL)
    {
      tmp = tmp->prev;
      i = i + 4;
    }
  if ((cmd = malloc((i + 2) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  i = 0;
  while (tmp != edit)
    {
      j = 0;
      while (tmp->c[j] && j < 4)
        cmd[i++] = tmp->c[j++];
      tmp = tmp->next;
    }
  cmd[i] = '\0';
  if (nbr == 4 && i == 0)
    return (str_null(ret));
  return (cmd);
}

char		*take_cmd_until(t_edit *edit)
{
  t_edit        *tmp;
  char          *cmd;
  int           j;
  int		i;

  tmp = ((i = 3) == 4) ? edit : edit;
  while (tmp->prev != NULL)
    {
      tmp = tmp->prev;
      i = i + 4;
    }
  if ((cmd = malloc((i + 2) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  i = 0;
  while (tmp != edit && tmp->actual != 1)
    {
      j = 0;
      while (tmp->c[j] && j < 4)
        cmd[i++] = tmp->c[j++];
      tmp = tmp->next;
    }
  cmd[i] = '\0';
  return (cmd);
}

char		*take_cmd_comp(t_edit *edit)
{
  t_edit        *tmp;
  char          *cmd;
  int           j;
  int		i;

  tmp = ((i = 3) == 3) ? edit : edit;
  while (tmp->prev != NULL && tmp->actual != 1 && i++)
    tmp = tmp->prev;
  if (tmp->c[0] == ' ' && tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp->prev != NULL && tmp->c[0] != ' ' && i++)
    tmp = tmp->prev;
  if (tmp->c[0] == ' ' && tmp->next != NULL)
    tmp = tmp->next;
  if ((cmd = malloc(((i * 16) + 2) * sizeof(char))) == NULL || ((i = 0) != 0))
    return (my_errors("Malloc : error\n", NULL));
  while (tmp != edit && tmp != NULL && tmp->c[0] != ' ' && tmp->actual != 1)
    {
      j = 0;
      while (tmp->c[j] && j < 4)
        cmd[i++] = tmp->c[j++];
      tmp = tmp->next;
    }
  cmd[i] = '\0';
  return (cmd);
}
