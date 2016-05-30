/*
** my_third_action.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Jan 10 14:45:32 2015 Florian Saurs
** Last update Fri May 22 00:43:49 2015 guillaume wilmot
*/

#include "edit.h"

void	my_left(t_tools tool, t_list **list, int buff, struct winsize argp)
{
  int	cmpt;
  int	nbr;

  nbr = 1;
  if (buff == LEFT)
    {
      cmpt = (*list)->cmpt;
      (*list) = (*list)->next;
      while ((*list)->cmpt != cmpt)
	{
	  (*list) = (*list)->next;
	  ++nbr;
	}
      if ((*list)->cmpt - argp.ws_row + 2 >= 0)
	{
	  (*list)->pos = 0;
	  while (argp.ws_row - 2 > 0)
	    {
	      (*list) = (*list)->prev;
	      --argp.ws_row;
	    }
	  (*list)->pos = 1;
	  my_show_list(*list, tool, tool.command);
	}
    }
}

void	print_my_list_right(t_list **list, struct winsize argp, t_tools tool)
{
  (*list)->pos = 0;
  while (argp.ws_row - 2 > 0)
    {
      (*list) = (*list)->next;
      --argp.ws_row;
    }
  (*list)->pos = 1;
  my_show_list(*list, tool, tool.command);
}

void	my_right(t_tools tool, t_list **list, int buff, struct winsize argp)
{
  int	cmpt;
  int	nbr;
  int	max;

  nbr = 1;
  if (buff == RIGHT)
    {
      cmpt = (*list)->cmpt;
      max = cmpt;
      (*list) = (*list)->next;
      while ((*list)->cmpt != cmpt)
	{
	  if ((*list)->cmpt > max)
	    max = (*list)->cmpt;
	  (*list) = (*list)->next;
	  ++nbr;
	}
      if (nbr > argp.ws_row - 2 && (*list)->cmpt + argp.ws_row - 2 <= max)
	print_my_list_right(list, argp, tool);
    }
}

void			my_next(t_tools tool, t_list **list, int buff)
{
  struct winsize        argp;
  struct termios	tmp;

  tmp.c_iflag = 0;
  if (ioctl (0, TIOCGWINSZ, &argp) == -1)
    {
      my_restore(tool, tmp);
      my_errors("Ioctl : error\n", NULL);
    }
  my_left(tool, list, buff, argp);
  my_right(tool, list, buff, argp);
}

void	my_conditions(t_tools tool, t_list **list, int buff)
{
  if (buff == DOWN || buff == 9)
    {
      (*list)->pos = 0;
      (*list) = (*list)->next;
      (*list)->pos = 1;
      my_show_list(*list, tool, tool.command);
    }
  else if (buff == UP)
    {
      (*list)->pos = 0;
      *list = (*list)->prev;
      (*list)->pos = 1;
      my_show_list(*list, tool, tool.command);
    }
}
