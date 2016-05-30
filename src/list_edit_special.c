/*
** list_edit_special.c for list_edit_special in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 14 00:08:09 2015 guillaume wilmot
** Last update Tue May 19 12:31:07 2015 guillaume wilmot
*/

#include "edit.h"

int		my_put_in_s_edit_next(t_edit **list, char *c)
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
      while (ptr_temp->prev != NULL && ptr_temp->prev->actual != 1)
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
