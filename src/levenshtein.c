/*
** levenshtein.c for  in /Users/Kevin/PSU_2014_42sh/Levenshtein
**
** Made by Kevin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Tue May 12 17:24:39 2015 Kevin Empociello
** Last update Sun May 31 22:59:34 2015 guillaume wilmot
*/

#include "edit.h"

int	leven_min(char **dic, char *command)
{
  int	a;
  int	distance;
  int	best;

  best = 0;
  distance = 0;
  a = 0;
  while (dic[a] != NULL)
    {
      distance = give_distance(dic[a], command);
      if (a == 0)
	best = distance;
      if (distance < best)
	best = distance;
      a++;
    }
  if (best > 4)
    return (-1);
  return (best);
}

char	*leven(char **dic, char *command)
{
  int	best;
  char	*tmp;
  char	*s;

  if ((best = leven_min(dic, command)) == -1)
    return (NULL);
  else
    {
      tmp = keyboard_precision(dic, command, best);
      printf("\nDid you mean : %s ? (y/n)\n", tmp);
      if ((s = get_next_line(0)) == NULL)
	return (NULL);
      if (strcmp(s, "y") == 0)
	{
	  free(s);
	  return (strdup(tmp));
	}
      else
	{
	  free(s);
	  return (NULL);
	}
    }
  return (NULL);
}

char	*levenshtein(char *str, UNUSED char **env)
{
  char	**dic;
  char	**command;
  int	i;
  int	pos;

  i = 0;
  pos = 0;
  command = cut_command(str);
  if ((dic = gen_data(save_my_env(NULL))) == NULL)
    return (str);
  while (command && command[i] != NULL)
    {
      if (i == 0 || is_separator_ext(command[i - 1][0]) == 0)
	{
	  if (check_command(command[i], save_my_env(NULL)) == -1)
	    {
	      pos = where_is_space(command[i]);
	      command[i] = change_command(command[i],
					  leven(dic, po_s(command[i], pos)));
	    }
	}
      i++;
    }
  free_array_char(dic);
  return (tab_string(command));
}
