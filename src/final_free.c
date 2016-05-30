/*
** final_free.c for final_free in /home/wilmot_g/minishell2
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Feb 17 22:21:42 2015 guillaume wilmot
** Last update Fri May 22 18:03:00 2015 guillaume wilmot
*/

#include "edit.h"

void	free_double_tab(char **tabl)
{
  int   i;

  if (tabl != NULL)
    {
      i = 0;
      while (tabl[i])
        {
          if (tabl[i] != NULL)
            free(tabl[i]);
          i++;
        }
      free(tabl);
    }
}

void	my_free(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}

void	my_final_free(char **paths, char *buffed, char **env, t_hist *hist)
{
  int	i;

  i = 0;
  if (paths != NULL)
    {
      while (paths[i])
	free(paths[i++]);
      free(paths);
    }
  i = 0;
  if (env != NULL)
    {
      while (env[i])
	free(env[i++]);
      free(env);
    }
  if (buffed != NULL)
    free(buffed);
  free_hist(hist);
}
