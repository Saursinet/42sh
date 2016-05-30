/*
** my_param_term.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Jan  7 14:09:32 2015 Florian Saurs
** Last update Fri May 22 07:21:55 2015 guillaume wilmot
*/

#include "edit.h"

void			change_mod()
{
  struct termios	t;

  if (tcgetattr(0, &t) != -1)
    {
      t.c_lflag &= ~ICANON;
      t.c_lflag &= ~ECHO;
      t.c_cc[VMIN] = 1;
      t.c_cc[VTIME] = 0;
    }
  else
    my_errors("tcgetattr : error\n", NULL);
  if (tcsetattr(0, TCSANOW, &t) == -1)
    my_errors("tcsetattr : error\n", NULL);
}

static struct termios	my_keep_term(struct termios my_term)
{
  static struct termios tmp;

  if (my_term.c_iflag != 0)
    tmp = my_term;
  return (tmp);
}

int		my_struct(t_tools *tool, char *term, char *command,
			  char *folder)
{
  tool->i = 0;
  tool->termtype = term;
  tool->command = command;
  tool->folder = folder;
  if ((tool->term_buffer = malloc(2048)) == NULL)
    return (my_int_errors("Malloc : error\n", -1));
  if ((tool->success = tgetent(tool->term_buffer, tool->termtype)) <= 0)
    return (my_int_errors("Tgetent : error\n", -1));
  if ((tool->clear_line = tgetstr("cl", NULL)) == NULL ||
      (tool->color_string = tgetstr("mr", NULL)) == NULL ||
      (tool->color_end_string = tgetstr("me", NULL)) == NULL ||
      (tool->underline_string = tgetstr("us", NULL)) == NULL ||
      (tool->underline_end_string = tgetstr("ue", NULL)) == NULL ||
      (tool->return_line = tgetstr("do", NULL)) == NULL ||
      (tool->set_cursor = tgetstr("cm", NULL)) == NULL ||
      (tool->invisible_cursor = tgetstr("vi", NULL)) == NULL ||
      (tool->gras_text = tgetstr("md", NULL)) == NULL ||
      (tputs(tool->underline_string, 1, &my_putchar_int)) == -1)
    return (my_int_errors("Tgetstr : error\n", -1));
  my_keep_tool(*tool);
  return (0);
}

void			my_restore(t_tools my_tool, struct termios my_term)
{
  static t_tools	tool;
  static struct termios	tmp;

  tool = my_keep_tool(my_tool);
  tmp = my_keep_term(my_term);
  if ((tool.cl_string = tgetstr("me", NULL)) != NULL)
    {
      tputs(tool.cl_string, 1, &my_putchar_int);
      tputs(tool.clear_line, 1, &my_putchar_int);
    }
  if ((tool.visible_cursor = tgetstr("ve", NULL)) !=  NULL)
    tputs(tool.visible_cursor, 1, &my_putchar_int);
  tcsetattr(0, TCSANOW, &tmp);
}
