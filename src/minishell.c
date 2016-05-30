/*
** minishell.c for minichell in /home/saurs_f
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Jan  7 10:55:58 2015 Florian Saurs
** Last update Sun May 24 21:59:00 2015 guillaume wilmot
*/

#include "minishell.h"

char	**my_affect_line(char *s, int i, char **arg)
{
  int	tmp;
  int	c;

  tmp = i;
  c = 0;
  while (s && s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != ':')
    ++i;
  while (arg[c] != NULL)
    ++c;
  if ((arg[c] = malloc(((i) * 20 + 200) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s && s[tmp] && s[tmp] != ' ' && s[i] != '\t' && s[tmp] != ':')
    arg[c][i++] = s[tmp++];
  arg[c][i] = 0;
  arg[c + 1] = NULL;
  return (arg);
}

char	**my_str_to_wordtab(char *s)
{
  char	**arg;
  int	i;
  int	c;

  i = 0;
  c = 1;
  while (s[i] != 0)
    {
      if (s[i] == ' ' || s[i] == '\t' || s[i] == ':')
	++c;
      ++i;
    }
  i = 0;
  if ((arg = malloc((c + 1) * sizeof(char *))) == NULL)
    return (NULL);
  arg[0] = NULL;
  while (s[i] != 0)
    {
      arg = my_affect_line(s, i, arg);
      while (s[i] != 0 && s[i] != ' '  && s[i] != '\t' &&  s[i] != ':')
	++i;
      while (s[i] == ' ' || s[i] == '\t' || s[i] == ':')
	++i;
    }
  return (arg);
}

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < nb)
    ++i;
  i = s1[i] - s2[i];
  return (i);
}

char	*my_strlcpy(char *name, char *command)
{
  int	i;
  int	j;
  char	*my_command;
  int	length;
  int	len;

  i = 0;
  j = 0;
  len = my_strlen(command);
  length = my_strlen(name);
  if ((my_command = malloc(sizeof(char *) * (length + len + 2))) == NULL)
    return (NULL);
  while (name[i] != 0)
    {
      my_command[i] = name[i];
      ++i;
    }
  my_command[i++] = '/';
  while (command[j] != 0)
    my_command[i++] = command[j++];
  my_command[i] = 0;
  return (my_command);
}

int	len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str[i] != '=')
    ++i;
  return (i);
}
