/*
** funct_ctrl_z.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/42sh
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sat May 23 18:20:47 2015 Florian Saurs
** Last update Sun May 31 13:01:35 2015 Florian Saurs
*/

#include "minishell.h"

int	*init_job()
{
  int	*jobs;

  if ((jobs = malloc(1 * sizeof(int))) == NULL)
    return (NULL);
  jobs[0] = -1;
  jobs = update_jobs(jobs, 1);
  return (jobs);
}

void	ctrl_z()
{
  save_pid(1, 0);
}

void	close_fg(int *jobs, int i)
{
  jobs = update_jobs(jobs, 0);
  while (jobs[i] != -1)
    ++i;
  if (i > 0)
    --i;
  while (i >= 0)
    {
      if (jobs[i] != -1)
	kill(jobs[i], SIGKILL);
      jobs[i] = -1;
      --i;
    }
  free(jobs);
  if (save_pid(3, 0) != -1)
    kill(save_pid(3, 0), SIGKILL);
}
