/*
** redirection.c for minishell2 in /home/saursf/rendu/PSU_2014_minishell2
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Thu Mar  5 16:38:16 2015 Florian Saurs
** Last update Sun May 24 18:33:18 2015 Florian Saurs
*/

#include "minishell.h"

char	**complete_line(char **arg, char *s, int tmp, int c)
{
  int	i;

  if ((arg[c] = malloc((3) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s[tmp] == ' ')
    ++tmp;
  while (s[tmp] == '|' || s[tmp] == '>' || s[tmp] == '<')
    arg[c][i++] = s[tmp++];
  if (i == 0)
    arg[c] = NULL;
  else
    {
      arg[c][i] = 0;
      arg[c + 1] = NULL;
    }
  return (arg);

}

char	**line(char *s, int i, char **arg)
{
  int	tmp;
  int	c;

  tmp = i;
  c = 0;
  while (s[i] != '|' && s[i] != 0 && s[i] != '>' && s[i] != '<')
    ++i;
  while (arg[c] != NULL)
    ++c;
  if ((arg[c] = malloc((i - tmp + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s[tmp] == ' ')
    tmp++;
  while (s[tmp] != 0 && s[tmp] != '|' && s[tmp] != '>' && s[tmp] != '<')
    arg[c][i++] = s[tmp++];
  --i;
  while (i > 0 && arg[c][i] == ' ')
    --i;
  arg[c++][++i] = 0;
  return (complete_line(arg, s, tmp, c));
}

char	**my_wordfortab(char *s)
{
  char	**arg;
  int	i;
  int	c;

  i = 0;
  c = 1;
  while (s[i] != 0)
    {
      if (s[i] == '|' || s[i] == '>' || s[i] == '<')
	++c;
      ++i;
    }
  i = 0;
  if ((arg = malloc((c + 2) * 2 * sizeof(char *))) == NULL)
    return (NULL);
  arg[0] = NULL;
  while (s[i] != 0)
    {
      arg = line(s, i, arg);
      while (s[i] != 0 && s[i] != '|' && s[i] != '>' && s[i] != '<')
	++i;
      while (s[i] == '|' || s[i] == '>' || s[i] == '<')
	++i;
    }
  return (arg);
}
