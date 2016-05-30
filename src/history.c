/*
** history.c for history in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Fri May 22 12:21:36 2015 guillaume wilmot
** Last update Sun May 24 03:32:47 2015 guillaume wilmot
*/

#include "edit.h"

char	**str_to_word_tab(char *str)
{
  char	**tabl;
  int	i;
  int	k;
  int	j;

  i = 0;
  j = 0;
  while (str && str[i] && str[i] == ' ')
    i++;
  if ((tabl = malloc((my_strlen(str) + 2) * sizeof(char *))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (str && str[i])
    {
      if ((tabl[j] = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
        return (my_errors("Malloc : error\n", NULL));
      k = 0;
      while (str[i] && str[i] != ' ')
        tabl[j][k++] = str[i++];
      tabl[j][k] = '\0';
      while (str[i] && str[i] == ' ')
        i++;
      j++;
    }
  tabl[j] = NULL;
  return (tabl);
}

char	*replace_hist(int nb, t_hist *hist, char *str)
{
  int	i;

  i = 0;
  if (nb < 0)
    {
      nb = -nb;
      while (i < nb && hist != NULL)
	{
	  hist = hist->next;
	  i++;
	}
    }
  else
    {
      while (hist->next != NULL)
	hist = hist->next;
      while (i < nb && hist != NULL)
	{
	  hist = hist->prev;
	  i++;
	}
    }
  free(str);
  return (((hist == NULL) ? my_errors("Could not find this event\n", NULL) :
	   (take_cmd(hist->edit, 0, 0))));
}

char	*concat_tab(char **tabl)
{
  int	i;
  char	*tmp;
  char	*tmp2;

  i = 0;
  tmp = NULL;
  tmp2 = NULL;
  while (tabl[i])
    {
      tmp = concatenate(tmp2, tabl[i], ' ');
      free(tmp2);
      tmp2 = tmp;
      i++;
    }
  free_double_tab(tabl);
  return (tmp);
}

char		*histo_top(char *to_find, t_hist *hist, char *str)
{
  t_hist        *tmp_h;
  char          *tmp;

  if (hist == NULL || hist->next == NULL || hist->next->next == NULL)
    return (str);
  tmp_h = hist->next->next;
  tmp = take_cmd(tmp_h->edit, 0, 0);
  while (tmp_h != NULL && !hidden_match(tmp, to_find))
    {
      tmp_h = tmp_h->next;
      my_free(tmp);
      tmp = take_cmd(tmp_h->edit, 0, 0);
    }
  if (hidden_match(tmp, to_find))
    {
      free(str);
      return (tmp);
    }
  free(tmp);
  return (str);
}

void	replace_history_aliases(char **cmd, t_hist **hist)
{
  char	**tabl;
  int	i;

  if ((tabl = str_to_word_tab(*cmd)) != NULL)
    {
      i = 0;
      while (tabl[i])
	{
	  if (tabl[i][0] == '!')
	    {
	      if (tabl[i][1] == '!')
		tabl[i] = replace_hist(-2, *hist, tabl[i]);
	      else if ((tabl[i][1] < '0' || tabl[i][1] > '9')
		       && tabl[i][1] != '-')
		tabl[i] = histo_top(&tabl[i][1], *hist, tabl[i]);
	      else
		tabl[i] = replace_hist(atoi(&tabl[i][1]) - 1, *hist, tabl[i]);
	    }
	  i++;
	}
      free(*cmd);
      *cmd = concat_tab(tabl);
    }
}
