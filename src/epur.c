/*
** epur.c for  in /home/empoci_k/PSU_2014_minishell2
**
** Made by kevin empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Sun Mar  8 22:43:16 2015 kevin empociello
** Last update Sun May 24 20:53:25 2015 guillaume wilmot
*/

#include "edit.h"

int	stop_function(char error, char *str)
{
  write(2, str, my_strlen(str));
  if (error != 0)
    {
      write(2, &error, 1);
      write(2, "\n", 1);
    }
  return (-1);
}

void	extends(int k, char *tmp)
{
  if (k == 0)
    tmp[k] = '\0';
  else
    {
      if (tmp != NULL && tmp[k - 1] == ' ')
	k--;
      tmp[k] = '\0';
    }
}

int	loop_epur(char *str, int i)
{
  if (str[i + 1] && (str[i + 1] == '|' || str[i + 1] == ';' ||
		     str[i + 1] == '&' || str[i + 1] == '>' ||
		     str[i + 1] == '<' || str[i + 1] == '`') &&
      str[i] != ' ' && str[i] != '&' && str[i] != '|' &&
      str[i] != ';' && str[i] != '>' && str[i] != '<' &&
      str[i] != '`')
    return (1);
  return (0);
}

char	*epur_42sh(char *str, int i, int j, char *new)
{
  if ((new = malloc((my_strlen(str) * 3 + 2) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (str[i])
    {
      if (loop_epur(str, i))
	{
	  new[j++] = str[i];
	  new[j++] = ' ';
	}
      else if (i > 0 && ((str[i - 1] == '|' || str[i - 1] == ';' ||
			  str[i - 1] == '&' || str[i - 1] == '>' ||
			  str[i - 1] == '<' || str[i - 1] == '`') &&
			 str[i] != ' ' && str[i] != '&' && str[i] != '|' &&
			 str[i] != ';' && str[i] != '>' && str[i] != '<' &&
			 str[i] != '`'))
	{
	  new[j++] = ' ';
	  new[j++] = str[i];
	}
      else
	new[j++] = str[i];
      ++i;
    }
  ((new[j] = '\0') == '\0') ? free(str) : free(str);
  return (new);
}

char	*my_epur(char *str)
{
  char	*tmp;
  int	i;
  int	k;

  i = ((k = 0) == 0) ? 0 : 0;
  if ((tmp = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (str[i] && (str[i] == ' ' || str[i] == 9))
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == 9)
	{
	  while (str[i] && (str[i] == ' ' || str[i] == 9))
	    i++;
	  tmp[k] = ' ';
	  i--;
	}
      else
	tmp[k] = str[i];
      i = ((k = k + 1) != -42) ? i + 1 : i + 1;
    }
  extends(k, tmp);
  free(str);
  return (epur_42sh(tmp, 0, 0, NULL));
}
