/*
** separate_strings.c for separate_strings in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Wed May 13 23:17:54 2015 guillaume wilmot
** Last update Tue May 19 12:40:53 2015 guillaume wilmot
*/

#include "edit.h"

void		concat_specials(t_edit **edit, t_edit *back, t_edit *tmp)
{
  int		i;

  if ((tmp = *edit) != NULL)
    {
      while (tmp->prev != NULL)
	tmp = tmp->prev;
      while (tmp->next != NULL)
	{
	  i = 1;
	  while (tmp != *edit && tmp != NULL && tmp->c[0] < 0 && tmp->next != NULL
		 && tmp->next && tmp->next->c[0] < 0 && i < 2)
	    {
	      tmp->next->actual = 1;
	      tmp->c[i++] = tmp->next->c[0];
	      tmp->c[i] = '\0';
	      spe_suppr(edit, NULL);
	    }
	  tmp = tmp->next;
	  if (tmp != NULL)
	    tmp->actual = 0;
	}
      if (back != NULL)
	back->actual = 1;
    }
}

void		sep_strings(t_edit **edit, t_edit **tmp, char buf[2])
{
  int		i;

  while ((*tmp)->next != NULL)
    {
      i = my_strlen((*tmp)->c) - 1;
      while (i > 0)
	{
	  (*tmp)->actual = 1;
	  buf[0] = (*tmp)->c[i--];
	  my_put_in_s_edit_next(edit, buf);
	  (*tmp)->next->actual = 0;
	}
      (*tmp)->c[1] = '\0';
      (*tmp)->actual = 0;
      (*tmp) = (*tmp)->next;
    }
}

void		separate_strings(t_edit **edit)
{
  char		buf[2];
  t_edit	*tmp;
  t_edit	*back;

  if ((tmp = *edit) != NULL)
    {
      buf[1] = '\0';
      back = NULL;
      while (tmp->prev != NULL)
	{
	  if (tmp->actual == 1)
	    back = tmp;
	  tmp->actual = 0;
	  tmp = tmp->prev;
	}
      if (tmp->actual == 1)
	back = tmp;
      tmp->actual = 0;
      sep_strings(edit, &tmp, buf);
    }
  concat_specials(edit, back, tmp);
}
