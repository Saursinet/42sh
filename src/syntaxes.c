/*
** syntaxes.c for syntaxes in /home/wilmot_g/.ssh/PSU_2014_42sh/42sh/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 24 09:00:12 2015 guillaume wilmot
** Last update Sun May 31 21:40:48 2015 guillaume wilmot
*/

#include "edit.h"

int	check_acces(char *tabl, char **path)
{
  char	*s;
  int	i;

  i = 0;
  while (path && path[i] && tabl &&
	 access((s = concatenate(path[i], tabl, '/')), F_OK)
	 == -1)
    {
      free(s);
      i++;
    }
  if (path && path[i] && tabl &&
      access((s = concatenate(path[i], tabl, '/')), F_OK) == -1)
    {
      free(s);
      my_int_errors(tabl, -1);
      return (my_int_errors(" : Command not found\n", -1));
    }
  return (1);
}

int	check_pipe_follow(char **tabl)
{
  int	i;

  i = 0;
  while (tabl[i])
    {
      if (tabl[i][0] == '|' || tabl[i][0] == '>' || tabl[i][0] == '<')
	{
	  i++;
	  if (!tabl[i])
	    return (stop_function(tabl[i - 1][0], "42sh: syntax error near "));
	}
      else
	i++;
    }
  return (1);
}

int	check_file_and_binaries(char **tabl, char **path)
{
  int	i;
  int	ok;

  i = 0;
  while (tabl[i])
    {
      ok = 0;
      if (is_separator(tabl[i][0]))
	ok = 1;
      if (i == 0 || ok)
	if (!check_acces(tabl[i], path))
	  return (-1);
      i++;
    }
  return (check_pipe_follow(tabl));
}

int	check_syntaxes(char **tabl, char **path)
{
  int	i;
  int	is;

  i = 0;
  is = 0;
  if (tabl[0] && !is_separator(tabl[0][0]))
    return (my_int_errors("Wrongly placed separator\n", -1));
  while (tabl[i])
    {
      if (!is_separator(tabl[i][0]) && is == 0)
	is = 1;
      else if (!is_separator(tabl[i][0]) && is == 1)
	return (my_int_errors("Stacked separators\n", -1));
      else
	is = 0;
      i++;
    }
  return (check_file_and_binaries(tabl, path));
}
