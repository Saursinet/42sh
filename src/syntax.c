/*
** syntax.c for syntax in /home/wilmot_g/minishell
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun Feb 15 23:00:48 2015 guillaume wilmot
** Last update Sun May 31 21:38:46 2015 guillaume wilmot
*/

#include <edit.h>

int	syntax_pipes(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '|')
    {
      i++;
      if (!str[i])
	return (1);
      if (str[i] != '|')
	return (stop_function(str[i - 1], "42sh: syntax error near "));
      i++;
      if (str[i])
	return (stop_function(str[i], "42sh: syntax error near "));
    }
  return (1);
}

int	syntax_redir(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '<' || str[i] == '>')
    {
      i++;
      if (!str[i])
	return (1);
      if (str[i] != str[i - 1])
	return (stop_function(str[i], "42sh: syntax error near "));
      i++;
      if (str[i])
	return (stop_function(str[i], "42sh: syntax error near "));
    }
  return (1);
}

int	syntax_general(char *str)
{
  int	i;

  i = 0;
  if (str[i] == ';')
    if (str[i + 1])
      return (stop_function(str[i], "42sh: syntax error near "));
  return (1);
}

int	syntax_and(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '&')
    {
      i++;
      if (str[i + 1])
	return (stop_function(str[i], "42sh: syntax error near "));
    }
  return (1);
}

int	check_syntax(char *str, char **path)
{
  int	i;
  int	ok;
  char	**tabl;

  i = 0;
  ok = 1;
  if ((tabl = str_to_word_tab(str)) == NULL)
    return (0);
  while (tabl[i] && ok == 1)
    {
      if ((ok = syntax_redir(tabl[i])) != 1 ||
	  (ok = syntax_pipes(tabl[i])) != 1 ||
	  (ok = syntax_general(tabl[i])) != 1 ||
	  (ok = syntax_and(tabl[i])) != 1)
	{
	  free_double_tab(tabl);
	  return (-1);
	}
      i = i + 1;
    }
  ok = check_syntaxes(tabl, path);
  free_double_tab(tabl);
  return ((ok != 1) ? -1 : 1);
}
