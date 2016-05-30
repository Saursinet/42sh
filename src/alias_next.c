/*
** alias_next.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/saursinet/42sh
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sun May 24 07:51:43 2015 Florian Saurs
** Last update Sun May 31 23:26:37 2015 guillaume wilmot
*/

#include "minishell.h"

char		*my_take_place(char *src, char *dest, int end)
{
  char		*tmp;
  int		i;
  int		j;

  if ((tmp = malloc((my_strlen(src) + my_strlen(dest)) * sizeof(char))) == NULL)
    return (0);
  i = -1;
  while (src[++i] != dest[6])
    tmp[i] = src[i];
  j = end;
  while (dest[j] != '\'')
    tmp[i++] = dest[j++];
  j = -1;
  while (src[++j] != dest[6]);
  end = 6;
  while (src[j] == dest[end])
    {
      ++j;
      ++end;
    }
  while (src[j])
    tmp[i++] = src[j++];
  tmp[i] = 0;
  free(src);
  return (tmp);
}

int		is_a_path(char *str)
{
  int		i;
  int		space;

  i = 0;
  space = 0;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	++space;
      if (str[i] == '/' && space == 0)
	return (1);
      ++i;
    }
  return (0);
}

char		*find_it(char **tabl, char *cmd, int i)
{
  int		j;
  int		c;

  i = -1;
  while (tabl[++i])
    {
      if (tabl[i][0] != '#' && is_alias(tabl[i]) == 0 && is_a_path(cmd) == 0)
	{
	  j = 6;
	  c = 0;
	  while (cmd[c] && cmd[c] != tabl[i][j])
	    ++c;
	  if (c == 0 || is_separator_ext(cmd[c - 1]))
	    {
	      while (cmd[c] == tabl[i][j])
		{
		  ++c;
		  ++j;
		}
	      if (tabl[i][j] == '=' && (cmd[c] == 0 || cmd[c] == ' '))
		cmd = my_take_place(cmd, tabl[i], j + 2);
	    }
	}
    }
  return (cmd);
}

char	*take_my_export_second(char *str)
{
  int	i;
  int	j;
  int	tmp;
  char	*s2;

  i = 0;
  while (str[i] && str[i] != '=')
    ++i;
  j = i;
  while (str[i])
    ++i;
  if (tmp = 0, (s2 = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[++j])
    s2[tmp++] = str[j];
  s2[tmp] = 0;
  return (s2);

}

char	*take_my_export_first(char *str)
{
  int	i;
  int	j;
  int	tmp;
  char	*s1;

  i = 0;
  while (str[i] && str[i] != ' ')
    ++i;
  j = i;
  while (str[i] && str[i] != '=')
    ++i;
  if (tmp = 0, (s1 = malloc((i - j + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[++j] && str[j] != '=')
    s1[tmp++] = str[j];
  s1[tmp] = 0;
  return (s1);
}
