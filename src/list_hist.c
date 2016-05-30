/*
** list_hist.c for list_hist in /home/wilmot_g/minishell2
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun Mar  8 19:31:15 2015 guillaume wilmot
** Last update Thu Apr 30 19:03:31 2015 guillaume wilmot
*/

#include "edit.h"

int		my_edit_free(t_edit *edit)
{
  t_edit	*tmp;

  if (edit == NULL)
    return (0);
  while (edit != NULL)
    {
      free(edit->c);
      tmp = edit;
      edit = edit->prev;
      free(tmp);
    }
  return (0);
}

t_edit		*my_edit_dup(t_edit *edit)
{
  t_edit	*new;
  t_edit	*tmp;

  if (edit == NULL)
    return (NULL);
  new = NULL;
  my_put_in_s_edit(&new, my_strdup(edit->c));
  tmp = edit;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp != edit)
    {
      my_put_in_s_edit(&new, tmp->c);
      tmp = tmp->next;
    }
  return (new);
}

t_edit		*root_hist()
{
  t_edit	*elem;

  if ((elem = malloc(sizeof(t_edit))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  elem->c = my_strdup(" ");
  elem->next = NULL;
  elem->prev = NULL;
  return (elem);
}

int		free_hist(t_hist *hist)
{
  t_hist	*tmp;

  if (hist == NULL)
    return (0);
  while (hist->prev != NULL)
    hist = hist->prev;
  while (hist != NULL)
    {
      my_edit_free(hist->edit);
      tmp = hist;
      hist = hist->next;
      free(tmp);
    }
  return (0);
}

int		my_put_in_s_hist(t_hist **list, t_edit *edit)
{
  t_hist	*elem;

  if ((elem = malloc(sizeof(t_hist))) == NULL)
    return (my_int_errors("Malloc : error\n", -1));
  elem->edit = edit;
  elem->next = NULL;
  elem->prev = NULL;
  if (*list != NULL)
    {
      while ((*list)->prev != NULL)
	*list = (*list)->prev;
      elem->next = (*list)->next;
      (*list)->next = elem;
      elem->prev = *list;
      if (elem->next != NULL)
	elem->next->prev = elem;
    }
  else
    *list = elem;
  return (0);
}
