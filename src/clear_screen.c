/*
** clear_screen.c for clear_screen in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May  4 11:24:27 2015 guillaume wilmot
** Last update Mon May 18 20:26:52 2015 guillaume wilmot
*/

#include "edit.h"

char		*my_clear(char *term)
{
  char		*str;
  char          *term_buffer;

  term_buffer = NULL;
  if (tgetent(term_buffer, term) != 1)
    return (my_errors("\nTgetent : error. Could not clear\n", NULL));
  if ((str = tgetstr("cl", NULL)) == NULL)
    return (my_errors("\nTgetstr : error. Could not clear\n", NULL));
  tputs(str, 1, &my_putchar_int);
  return (NULL);
}
