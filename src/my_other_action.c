/*
** my_other_action.c for my_select in /home/saursf/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Jan 10 13:42:29 2015 Florian Saurs
** Last update Sun May 31 21:00:39 2015 guillaume wilmot
*/

#include "edit.h"

void		my_order(t_list **list)
{
  char		*str;
  int		c;
  char		a;
  char		b;

  while ((*list)->cmpt != 0 && (*list)->param)
    {
      c = 0;
      while ((*list)->param[c] == (*list)->prev->param[c])
	++c;
      a = my_min((*list)->param[0]);
      b = my_min((*list)->prev->param[0]);
      if (a < b || (a == b && my_min((*list)->param[c])
		    < my_min((*list)->prev->param[c])))
	{
	  str = (*list)->param;
	  (*list)->param = (*list)->prev->param;
	  (*list)->prev->param = str;
	  while ((*list)->prev->cmpt != 0)
	    *list = (*list)->next;
	}
      else
	*list = (*list)->next;
    }
}

void		my_inverse(t_list **list)
{
  char          *str;
  int           c;
  char          a;
  char          b;

  while ((*list)->cmpt != 0 && (*list)->param)
    {
      c = 0;
      while ((*list)->param[c] == (*list)->prev->param[c])
        ++c;
      a = my_min((*list)->param[0]);
      b = my_min((*list)->prev->param[0]);
      if (a > b ||
          (a == b && my_min((*list)->param[c]) >
	   my_min((*list)->prev->param[c])))
        {
          str = (*list)->param;
          (*list)->param = (*list)->prev->param;
          (*list)->prev->param = str;
          while ((*list)->prev->cmpt != 0)
            *list = (*list)->next;
        }
      else
        *list = (*list)->next;
    }
}

void		my_empty_selection(t_list **list, t_tools tool)
{
  int		cmpt;

  cmpt = (*list)->cmpt;
  if ((*list)->select == 1)
    (*list)->select = 0;
  *list = (*list)->next;
  while ((*list)->cmpt != cmpt)
    {
      if ((*list)->select == 1)
        (*list)->select = 0;
      *list = (*list)->next;
    }
  my_show_list(*list, tool, tool.command);
}

void		my_list_in_order(t_list **list, t_tools tool, int i)
{
  char		*str;

  str = (*list)->param;
  my_empty_selection(list, tool);
  (*list)->pos = 0;
  while ((*list)->cmpt != 0)
    *list = (*list)->next;
  *list = (*list)->next;
  if (i == 0)
    my_order(list);
  else
    my_inverse(list);
  while ((*list)->param != str)
    *list = (*list)->next;
  (*list)->pos = 1;
  if (tputs(tool.clear_line, 1, &my_putchar_int) != -1)
    my_show_list(*list, tool, tool.command);
}
