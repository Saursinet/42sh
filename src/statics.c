/*
** statics.c for statics in /home/wilmot_g/.ssh/PSU_2014_42sh/saursinet/mini2/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 24 20:55:21 2015 guillaume wilmot
** Last update Sun May 24 23:11:39 2015 guillaume wilmot
*/

#include "edit.h"

int		get_return_value(int val, int stop, int update, int which)
{
  static int	tmp = 0;
  static int	tmp_stop = 0;

  if (update != 0)
    {
      tmp = val;
      tmp_stop = stop;
    }
  return ((which == 1) ? tmp : tmp_stop);
}

char		*get_term(char *term)
{
  static char   *tmp = NULL;

  if (term != NULL)
    tmp = term;
  return (tmp);
}

int		is_too_much(int yes)
{
  static int    no = 0;

  if (yes != -1)
    no = yes;
  return (no);
}

char		**save_my_env(char **env)
{
  static char   **myenv = NULL;

  if (env != NULL)
    myenv = env;
  return (myenv);
}

t_hist		*get_hist(t_hist *hist)
{
  static t_hist	*tmp = NULL;

  if (hist != NULL)
    tmp = hist;
  return (tmp);
}
