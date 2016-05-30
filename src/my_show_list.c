/*
** my_show_list.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Dec 30 11:47:05 2014 Florian Saurs
** Last update Fri May 22 06:02:58 2015 guillaume wilmot
*/

#include "edit.h"

t_list			*my_keep_list(t_list *list)
{
  static t_list		*tmp = NULL;

  if (list != NULL)
    tmp = list;
  return (tmp);
}

t_tools			my_keep_tool(t_tools tool)
{
  static t_tools	tmp;

  if (tool.termtype != NULL)
    tmp = tool;
  return (tmp);
}

int			check_my_screen(t_list **list, t_param par,
					struct winsize argp)
{
  if (par.cmpt != 0)
    {
      par.length = my_strlen((*list)->param) + 2;
      par.cmpt = 0;
    }
  else
    par.cmpt = 1;
  while ((*list)->cmpt != 0 && par.cmpt < argp.ws_row - 1)
    {
      if (par.length < my_strlen((*list)->param) + 2)
	par.length = my_strlen((*list)->param) + 2;
      *list = (*list)->next;
      ++par.cmpt;
    }
  par.my_length = par.my_length + par.length;
  return (par.my_length);
}

int			my_screen(struct winsize argp, t_list *list)
{
  t_param		par;

  par.my_length = 0;
  par.cmpt = 0;
  par.length = my_strlen(list->param) + 2;
  list = list->next;
  while (list->cmpt != 0)
    par.my_length = check_my_screen(&list, par, argp);
  if (par.my_length > argp.ws_col)
    {
      my_putstr("Too much argument too print\n");
      return (-1);
    }
  return (par.my_length);
}

int			my_show_list(t_list *list, t_tools tool, char *command)
{
  struct winsize	argp;
  t_param		par;

  par.length = 0;
  par.my_cmpt = 2;
  if ((list = my_keep_list(list)) == NULL)
    return (-1);
  tool = my_keep_tool(tool);
  argp = init_my_ioctl();
  while (list && list->cmpt != 0)
    list = list->next;
  if (my_screen(argp, list) == -1 ||
      (tputs(tgoto(tool.set_cursor, 0, 0), 1, &my_putchar_int)) == -1)
    return (-1);
  prompt(NULL);
  my_putstr(command);
  my_putchar('\n');
  my_printer(&list, tool);
  while (list->cmpt != 0)
    {
      par.length = par.length + my_show(&list, tool, argp, par);
      if (par.my_cmpt == 2)
	par.my_cmpt = 1;
    }
  return (0);
}
