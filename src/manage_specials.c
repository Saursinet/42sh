/*
** manage_specials.c for manage_specials in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue May  5 15:22:17 2015 guillaume wilmot
** Last update Sun May 24 03:31:05 2015 guillaume wilmot
*/

#include "edit.h"

int	*get_specials()
{
  int	*specials;

  if ((specials = malloc(5 * sizeof(int))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  specials[0] = 4341;
  specials[1] = 4405;
  specials[2] = 2114152155;
  specials[3] = 2114156251;
  specials[4] = 2114143963;
  return (specials);
}

void	manage_specials(t_edit **edit, t_cmd *cmd, t_hist **hist)
{
  int	i;
  int	(*fptr[5])(t_edit **edit, t_hist **hist);
  int	*specials;

  i = 0;
  fptr[0] = &ctrl_right;
  fptr[1] = &ctrl_left;
  fptr[2] = &hist_top;
  fptr[3] = &hist_bottom;
  fptr[4] = &spe_suppr;
  specials = get_specials();
  if (specials != NULL)
    {
      while (i < 5)
        {
          if (specials[i] == cmd->buf_nbr)
            fptr[i](edit, hist);
          i++;
        }
    }
  free(specials);
}
