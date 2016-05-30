/*
** edit.c for edit in /home/wilmot_g/LOLOL/Edit
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu Mar  5 17:07:18 2015 guillaume wilmot
** Last update Sun May 24 02:52:03 2015 guillaume wilmot
*/

#include "edit.h"

int			set_canon(int on)
{
  struct termios        termios;

  if (isatty(0))
    {
      if ((tcgetattr(0, &termios)) != 0)
	return (my_int_errors("\nTcgetattr : error\n", -1));
      if (on == 1)
	{
	  termios.c_lflag &= ~ICANON;
	  termios.c_lflag &= ~ECHO;
	  termios.c_cc[VMIN] = 1;
	  termios.c_cc[VTIME] = 0;
	}
      else if (on == 0)
	{
	  termios.c_lflag |= ICANON;
	  termios.c_lflag |= ECHO;
	}
      if ((tcsetattr(0, TCSANOW, &termios)) == -1)
	return (my_int_errors("\nTcsetattr : error\n", -1));
    }
  return (0);
}

char			*get_position(char *term)
{
  char			*term_buffer;
  char			*str;

  term_buffer = NULL;
  if (tgetent(term_buffer, term) != 1)
    return (my_errors("Tgetent : error\n", NULL));
  if ((str = tgetstr("sc", NULL)) == NULL)
    return (my_errors("Tgetstr : error\n", NULL));
  tputs(tgoto(str, 0, 0), 1, &my_putchar_int);
  if ((str = tgetstr("rc", NULL)) == NULL)
    return (my_errors("Tgetstr : error\n", NULL));
  return (str);
}

char			*set_position(char *str, char *term)
{
  char			*term_buffer;

  term_buffer = NULL;
  if (tgetent(term_buffer, term) != 1)
    return (my_errors("\nTgetent : error\n", NULL));
  tputs(tgoto(str, 0, 0), 1, &my_putchar_int);
  if ((str = tgetstr("cd", NULL)) == NULL)
    return (my_errors("\nTgetstr : error\n", NULL));
  tputs(str, 1, &my_putchar_int);
  return (NULL);
}

int			set_visibility_cursor(char *term, int mode)
{
  char			*str;
  char			*term_buffer;

  term_buffer = NULL;
  if (tgetent(term_buffer, term) != 1)
    return (my_int_errors("\nTgetent : error\n", -1));
  if ((str = tgetstr(((mode == 0) ? "vi" : "ve"), NULL)) == NULL)
    return (my_int_errors("\nTgetstr : error\n", -1));
  tputs(str, 1, &my_putchar_int);
  return (0);
}

int			my_putstr_special(char *c, int mode, char *term)
{
  char			*term_buffer;
  char			*str;

  term_buffer = NULL;
  if (tgetent(term_buffer, term) != 1)
    return (my_int_errors("\nTgetent : error\n", -1));
  if ((str = tgetstr(((mode == 2) ? "us" : "mr"), NULL)) == NULL)
    return (my_int_errors("\nTgetstr : error\n", -1));
  tputs(str, 1, &my_putchar_int);
  my_putstr(c);
  if ((str = tgetstr(((mode == 2) ? "ue" : "me"), NULL)) == NULL)
    return (my_int_errors("\nTgestr : error\n", -1));
  tputs(str, 1, &my_putchar_int);
  return (0);
}
