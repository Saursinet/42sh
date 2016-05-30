/*
** print_list.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Jan  7 13:48:00 2015 Florian Saurs
** Last update Fri May 22 00:34:05 2015 guillaume wilmot
*/

#include "edit.h"

void	my_printer(t_list **list, t_tools tool)
{
  char	*path;
  char	*s;

  if ((path = concatenate(tool.folder, (*list)->param, '/')) != NULL)
    {
      s = NULL;
      tputs(tool.color_end_string, 1, &my_putchar_int);
      if ((*list)->pos == 1)
	tputs(tool.color_string, 1, &my_putchar_int);
      else
	my_putstr((s = get_color_style(path)));
      free(path);
      my_putstr((*list)->param);
      if ((*list)->pos == 1)
	tputs(tool.color_end_string, 1, &my_putchar_int);
      *list = (*list)->next;
      if (s != NULL)
	my_putstr("\033[0m");
    }
}

int	find_print(t_list *list, struct winsize argp)
{
  int	nb;
  int	nb_col;
  int	length;

  nb_col = 1;
  length = my_strlen(list->param) + 1;
  list = list->next;
  while (list->cmpt != 0)
    {
      if (length < my_strlen(list->param) + 1)
	length = my_strlen(list->param) + 1;
      list = list->next;
    }
  nb = list->prev->cmpt;
  while (nb / nb_col > argp.ws_row - 1)
    {
      ++nb_col;
      if (length * nb_col > argp.ws_col - 1)
	{
	  my_putstr("There are too many arguments :");
	  my_putstr(" you have to resize the window to print the elements.\n");
	  return (-1);
	}
    }
  return (nb_col);
}
