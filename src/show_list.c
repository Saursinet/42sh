/*
** show_list.c for show_list in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Jan 10 14:28:18 2015 Florian Saurs
** Last update Thu May 21 17:33:56 2015 guillaume wilmot
*/

#include "edit.h"

int	my_length(t_list *list)
{
  int	length;

  length = my_strlen(list->param + 1);
  list = list->next;
  while (list->cmpt != 0)
    {
      if (length < my_strlen(list->param) + 1)
	length = my_strlen(list->param) + 1;
      list = list->next;
    }
  return (length);
}

int	my_show(t_list **list, t_tools tool, struct winsize argp, t_param par)
{
  int	cmpt;
  int	length;
  int	row;

  row = 0;
  if (par.my_cmpt == 0)
    ++row;
  cmpt = 1;
  length = my_strlen((*list)->param) + 2;
  while ((*list)->cmpt != 0 && par.my_cmpt < argp.ws_row + row - 1)
    {
      tputs(tgoto(tool.set_cursor, par.length, par.my_cmpt), 1,
	    &my_putchar_int);
      if (length < my_strlen((*list)->param) + 2)
	length = my_strlen((*list)->param) + 2;
      ++cmpt;
      my_printer(list, tool);
      ++par.my_cmpt;
    }
  return (length);
}
