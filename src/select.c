/*
** main.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Dec 23 13:28:43 2014 Florian Saurs
** Last update Sun May 31 21:08:54 2015 guillaume wilmot
*/

#include "edit.h"

void			my_other_placement(t_tools tool, t_list **list,
					   int buff)
{
  my_conditions(tool, list, buff);
  my_next(tool, list, buff);
}

char			*my_str_cmp(char *term, char *env)
{
  int			i;
  int			c;
  int			size;

  i = 0;
  c = 0;
  while (i < 7 && env[i] == term[i] && term[i] != 0)
    ++i;
  if (term[i] == 0)
    {
      size = my_strlen(env) - i + 1;
      if ((term = malloc(size * sizeof(char))) == NULL)
	return (my_errors("Malloc : error\n", NULL));
      while (env[i] != 0)
	term[c++] = env[i++];
      term[c] = 0;
      return (term);
    }
  return (NULL);
}

void			free_my_list(t_list *list, t_tools tool)
{
  while (list->cmpt != 0)
    list = list->next;
  list = list->next;
  while (list->cmpt != 0)
    {
      list = list->next;
      free(list->prev);
    }
  free(list);
  free(tool.term_buffer);
}

void			put_pos(t_list **list)
{
  t_list		*tmp;

  tmp = *list;
  while (tmp->cmpt != 0)
    {
      tmp->pos = 0;
      tmp = tmp->next;
    }
  tmp->pos = 1;
  *list = tmp;
}

char			*selectt(char **av, char *term, char *command,
				char *folder)
{
  t_list		*list;
  t_tools		tool;
  struct termios	tmp;
  int			fd;
  char			*str;

  signal(SIGWINCH, &my_resize);
  tool.termtype = NULL;
  fd = 1;
  if (tcgetattr(fd, &tmp) < 0 || (my_struct(&tool, term, command, folder)) < 0
      || (list = init_my_list(av, tool)) == NULL)
    return (NULL);
  my_restore(tool, tmp);
  change_mod();
  put_pos(&list);
  if (tputs(tool.clear_line, 1, &my_putchar_int) == -1
      || tputs(tool.invisible_cursor, 1, &my_putchar_int) == -1)
    return (NULL);
  my_show_list(list, tool, command);
  str = my_placement(tool, list);
  my_restore(tool, tmp);
  set_visibility_cursor(term, 0);
  set_canon(1);
  free_my_list(list, tool);
  return (str);
}
