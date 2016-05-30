/*
** my_fct_built.c for 42sh in /home/saursf/42/src
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Fri May 22 15:44:59 2015 Florian Saurs
** Last update Sun May 24 22:02:48 2015 guillaume wilmot
*/

#include "minishell.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	c;
  char	*str;
  int	len;

  i = 0;
  c = 0;
  len = my_strlen(dest) + my_strlen(src);
  if ((str = malloc(sizeof(char) * (len + 2))) == NULL)
    return (NULL);
  while (dest[i] != 0)
    {
      str[i] = dest[i];
      ++i;
    }
  str[i++] = '/';
  while (src[c] != 0)
    str[i++] = src[c++];
  str[i] = 0;
  return (str);
}

char	**line_it(char *s, int i, char **arg)
{
  int	tmp;
  int	c;

  tmp = i;
  c = 0;
  while (s && s[i] && s[i] != '&' && s[i] != '|' && s[i] != ';')
    ++i;
  while (arg[c] != NULL)
    ++c;
  if ((arg[c] = malloc(((i) * 20 + 200) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s && s[tmp] && s[tmp] != '&' && s[tmp] != '|' && s[tmp] != ';')
    arg[c][i++] = s[tmp++];
  while (s && s[tmp] && (s[tmp] == '&' || s[tmp] == '|' || s[tmp] == ';'))
    arg[c][i++] = s[tmp++];
  arg[c][i] = 0;
  arg[c + 1] = NULL;
  return (arg);
}

char	**wordtab(char *s)
{
  char	**arg;
  int	i;
  int	c;

  i = 0;
  c = 1;
  while (s[i] != 0)
    {
      if (s[i] == '&' || s[i] == '|' || s[i] == ';')
	++c;
      ++i;
    }
  i = 0;
  if ((arg = malloc((c + 2) * sizeof(char *))) == NULL)
    return (NULL);
  arg[0] = NULL;
  while (s[i] != 0)
    {
      arg = line_it(s, i, arg);
      while (s[i] != 0 && s[i] != '&'  && s[i] != '|' &&  s[i] != ';')
	++i;
      while (s[i] == '&' || s[i] == '|' || s[i] == ';')
	++i;
    }
  return (arg);
}
