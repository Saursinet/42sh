/*
** exec_all.c for minishell in /home/saurs_f/rendu/PSU_2014_minishell1
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sun Feb  1 17:45:39 2015 Florian Saurs
** Last update Sun May 31 23:07:56 2015 guillaume wilmot
*/

#include "minishell.h"

char	**my_line(char *s, int i, char **arg, char car)
{
  int	tmp;
  int	c;

  tmp = i;
  c = 0;
  while (s[i] != car && s[i] != 0)
    ++i;
  while (arg[c] != NULL)
    ++c;
  if ((arg[c] = malloc((i - tmp + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s[tmp] == ' ')
    tmp++;
  while (s[tmp] != 0 && s[tmp] != car)
    arg[c][i++] = s[tmp++];
  arg[c][i] = 0;
  arg[c + 1] = NULL;
  return (arg);
}

char	**my_wordtab(char *s, char car)
{
  char	**arg;
  int	i;
  int	c;

  i = 0;
  c = 1;
  while (s && s[i] != 0)
    {
      if (s[i] == car)
	++c;
      ++i;
    }
  i = 0;
  if ((arg = malloc((c + 2) * sizeof(char *))) == NULL)
    return (NULL);
  arg[0] = NULL;
  while (s && s[i] != 0)
    {
      arg = my_line(s, i, arg, car);
      while (s[i] != 0 && s[i] != car)
	++i;
      while (s[i] == car)
	++i;
    }
  return (arg);
}

int	check_buff(char *s)
{
  if (s == NULL)
    return (-1);
  if (!strncmp("exit", s, 3) || !strncmp("cd", s, 1) ||
      !strncmp("history", s, 6) || !strncmp("setenv", s, 5) ||
      !strncmp("unsetenv", s, 7) || !strncmp("env", s, 2) ||
      !strncmp("fg", s, 1) || !strncmp("echo", s, 3))
    return (0);
  else
    return (-1);
}

int	is_true(char *str, int i)
{
  if ((str[i] == ';' || (str[i] == '&' && str[i + 1] != '\0' &&
			 str[i + 1] == '&') ||
       (str[i] == '|' && str[i + 1] != '\0' && str[i + 1] == '|')))
    return (1);
  return (0);
}

char	**wordtab_pars(char *str, char **tabl, int i, int j)
{
  int   k;

  k = 0;
  while (str && str[i])
    {
      if (is_true(str, i))
	{
	  tabl[j++][k] = '\0';
	  k = 0;
	  if ((tabl[j] = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
	    return (NULL);
	  while (str && str[i] != '\0' && str[i] != ' ')
	    tabl[j][k++] = str[i++];
	  tabl[j++][k] = '\0';
	  k = 0;
	  if ((tabl[j] = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
	    return (NULL);
	}
      tabl[j][k] = str[i];
      i++;
      k++;
    }
  tabl[j][k] = '\0';
  tabl[j + 1] = NULL;
  return (tabl);
}
