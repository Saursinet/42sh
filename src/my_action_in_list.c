/*
** my_term.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Thu Dec 25 19:03:09 2014 Florian Saurs
** Last update Fri May 22 06:45:14 2015 guillaume wilmot
*/

#include "edit.h"

char			*my_return(t_list *list)
{
  while (list->cmpt != 0)
    list = list->next;
  if (list->pos == 1)
    return (list->param);
  list = list->next;
  while (list->cmpt != 0)
    {
      if (list->pos == 1)
	return (list->param);
      list = list->next;
    }
  return (NULL);
}

char			*my_placement(t_tools tool, t_list *list)
{
  int			buff;
  int			ret;
  int			i;

  buff = 0;
  i = 0;
  while ((ret = read(0, &buff, 4)) != -1 || i < 100000)
    {
      if (ret == -1)
	i++;
      signal(SIGWINCH, &my_resize);
      if (buff == ENTER)
	return (my_return(list));
      if (buff == 127)
	return (NULL);
      my_other_placement(tool, &list, buff);
      buff = 0;
    }
  return (NULL);
}

void			my_resize()
{
  char			*str;
  t_list		*list;
  t_tools		tool;

  tool.termtype = NULL;
  tool = my_keep_tool(tool);
  list = my_keep_list(NULL);
  str = tgetstr("cl", NULL);
  if (tputs(str, 1, &my_putchar_int) != -1)
    my_show_list(list, tool, tool.command);
}

void			my_end()
{
  t_tools		tool;
  struct termios	tmp;

  tool.termtype = NULL;
  tmp.c_iflag = 0;
  my_restore(tool, tmp);
}

char			my_min(char c)
{
  if (c >= 'A' && c <= 'Z')
    c = c - 'A' + 'a';
  return (c);
}
