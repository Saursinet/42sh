/*
** list_edit.c for list_edit in /home/wilmot_g/LOLOL/Edit
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu Mar  5 17:14:41 2015 guillaume wilmot
** Last update Tue May  5 17:19:31 2015 guillaume wilmot
*/

#include "edit.h"

void		my_suppr_s_edit_link(t_edit *list)
{
  if (list->prev == NULL)
    list->next->prev = NULL;
  else
    {
      list->prev->next = list->next;
      list->next->prev = list->prev;
    }
  list->next->actual = 1;
  free(list);
}

t_edit		*my_remove_s_edit_link(t_edit *list)
{
  t_edit        *ptr_temp;

  ptr_temp = list;
  if (ptr_temp->prev == NULL && ptr_temp->next == NULL)
    ptr_temp = NULL;
  else if (ptr_temp->next == NULL)
    {
      ptr_temp->prev->next = NULL;
      ptr_temp = ptr_temp->prev;
    }
  else if (ptr_temp->prev == NULL)
    {
      ptr_temp->next->prev = NULL;
      ptr_temp = ptr_temp->next;
    }
  else
    {
      ptr_temp->prev->next = ptr_temp->next;
      ptr_temp->next->prev = ptr_temp->prev;
      ptr_temp = list->next;
    }
  free(list);
  return (ptr_temp);
}

int		my_put_in_s_edit(t_edit **list, char *c)
{
  t_edit        *ptr_temp;
  t_edit        *elem;

  if ((elem = malloc(sizeof(t_edit))) == NULL)
    return (my_int_errors("Malloc : error\n", -1));
  elem->c = my_strdup(c);
  elem->next = NULL;
  elem->prev = NULL;
  elem->actual = 1;
  if (*list != NULL)
    {
      ptr_temp = *list;
      while (ptr_temp->prev != NULL && ptr_temp->actual != 1)
        ptr_temp = ptr_temp->prev;
      elem->next = ptr_temp;
      elem->actual = 0;
      elem->prev = ptr_temp->prev;
      if (ptr_temp->prev != NULL)
	ptr_temp->prev->next = elem;
      ptr_temp->prev = elem;
    }
  else
    *list = elem;
  return (0);
}

int		my_show_s_edit(t_edit *list, char *term)
{
  t_edit        *ptr_temp;

  ptr_temp = list;
  if (ptr_temp == NULL)
    return (0);
  while (ptr_temp->prev != NULL)
    ptr_temp = ptr_temp->prev;
  while (ptr_temp != NULL)
    {
      if (ptr_temp->actual == 1)
	my_putstr_special(ptr_temp->c, 1, term);
      else
	my_putstr(ptr_temp->c);
      ptr_temp = ptr_temp->next;
    }
  return (0);
}

int		move_actual(t_edit **list, int which)
{
  t_edit        *ptr_temp;

  if ((ptr_temp = *list) == NULL)
    return (1);
  while (ptr_temp != NULL && ptr_temp->actual != 1)
    ptr_temp = ptr_temp->prev;
  if (which == 284379)
    {
      if (ptr_temp->prev != NULL)
	{
	  ptr_temp->prev->actual = 1;
	  ptr_temp->actual = 0;
	}
    }
  else if (which == 280283)
    {
      if (ptr_temp->next != NULL)
	{
	  ptr_temp->next->actual = 1;
	  ptr_temp->actual = 0;
	}
    }
  return (1);
}
