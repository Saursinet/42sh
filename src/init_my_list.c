/*
** mainbis.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Dec 23 14:18:20 2014 Florian Saurs
** Last update Fri May 22 06:06:56 2015 guillaume wilmot
*/

#include "edit.h"

int		my_put_in_list(t_list **list, char *av, int cpt)
{
  t_list	*elem;
  static int	i = 0;

  if (cpt == 0)
    i = 0;
  if ((elem = malloc(sizeof(**list))) == NULL)
    return (my_int_errors("Malloc : error\n", -1));
  elem->cmpt = i;
  elem->param = av;
  elem->select = 0;
  elem->pos = 0;
  elem->prev = *list;
  elem->next = 0;
  if (*list != NULL)
    (*list)->next = elem;
  *list = elem;
  ++i;
  return (0);
}

void		my_rotate_list(t_list **list)
{
  t_list	*tmp;

  if (*list != NULL)
    {
      tmp = *list;
      while ((*list)->prev != NULL)
	*list = (*list)->prev;
      (*list)->prev = tmp;
      tmp = *list;
      *list = (*list)->prev;
      (*list)->next = tmp;
      *list = (*list)->prev;
    }
}

t_list		*init_my_list(char **av, t_tools tool)
{
  t_list	*list;
  int		i;

  list = NULL;
  i = 0;
  while (av[i] != NULL)
    {
      if (i == 0)
	{
	  if (my_put_in_list(&list, av[i], 0) == -1)
	    return (NULL);
	}
      else
	if (my_put_in_list(&list, av[i], 1) == -1)
	  return (NULL);
      i++;
    }
  if (list == NULL)
    return (NULL);
  my_rotate_list(&list);
  while (list->cmpt != 0)
    list = list->next;
  my_list_in_order(&list, tool, 0);
  return (my_keep_list(list));
}

struct winsize		init_my_ioctl()
{
  struct winsize	argp;

  argp.ws_row = -1;
  if (ioctl (0, TIOCGWINSZ, &argp) == -1)
    my_errors("Ioctl : error\n", NULL);
  return (argp);
}
