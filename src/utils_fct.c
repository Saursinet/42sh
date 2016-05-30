/*
** utils_fct.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/42sh
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sat May 23 18:08:25 2015 Florian Saurs
** Last update Sun May 31 17:54:16 2015 guillaume wilmot
*/

#include "minishell.h"

char	**my_line_it(char *s, int i, char **arg)
{
  int	tmp;
  int	c;

  tmp = i;
  c = 0;
  while (s && s[i] && s[i] != '\n')
    ++i;
  while (arg && arg[c] != NULL)
    ++c;
  if (arg && (arg[c] = malloc(((i) * 20 + 100) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s && s[tmp] && s[tmp] != '\n')
    arg[c][i++] = s[tmp++];
  arg[c][i] = 0;
  arg[c + 1] = NULL;
  return (arg);
}

char	**my_str_wordtab(char *s)
{
  char	**arg;
  int	i;
  int	c;

  i = 0;
  c = 1;
  while (s && s[i] != 0)
    {
      if (s[i] == '\n')
	++c;
      ++i;
    }
  i = 0;
  if ((arg = malloc((c + 2) * sizeof(char *))) == NULL)
    return (NULL);
  arg[0] = NULL;
  while (s && s[i] != 0)
    {
      arg = my_line_it(s, i, arg);
      while (s[i] != 0 && s[i] != '\n')
	++i;
      while (s[i] == '\n')
	++i;
    }
  return (arg);
}

char	*my_add(char *str, char *tabl)
{
  char	*dest;
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (str == NULL)
    dest = malloc(my_strlen(tabl) + 1);
  else
    {
      if ((dest = malloc(my_strlen(str) + my_strlen(tabl) + 2)) == NULL)
	return (NULL);
      while (str && str[i] != 0)
	{
	  dest[i] = str[i];
	  ++i;
	}
      dest[i++] = '\n';
      my_free(str);
    }
  while (tabl[c] != 0)
    dest[i++] = tabl[c++];
  my_free(tabl);
  dest[i] = 0;
  return (dest);
}

char	*itos(int nb)
{
  char  *ret;
  int   i;
  int	a;

  i = 1;
  a = 0;
  if (nb / i > 9)
    i *= 10;
  if ((ret = malloc((15) * sizeof(char))) == NULL)
    return (NULL);
  while (i > 0)
    {
      ret[a++] = (nb / i) % 10 + 48;
      i /= 10;
    }
  ret[a] = '\0';
  return (ret);
}
