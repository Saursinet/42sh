/*
** ctrl_z.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/42sh/src
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sat May 23 15:49:55 2015 Florian Saurs
** Last update Sun May 31 16:54:23 2015 Florian Saurs
*/

#include "minishell.h"

int	*realloc_jobs(int *jobs, int pid)
{
  int	i;
  int	*tmp;

  i = 0;
  while (jobs[i++] != -1);
  if ((tmp = malloc(++i * sizeof(int))) == NULL)
    return (NULL);
  i = 0;
  while (jobs[i] != -1)
    {
      tmp[i] = jobs[i];
      ++i;
    }
  tmp[i++] = pid;
  tmp[i] = -1;
  free(jobs);
  return (tmp);
}

int		my_jobs(int act, int nb)
{
  static int	*jobs = NULL;
  int		i;
  int		save;

  i = 0;
  if (act == 0)
    {
      while (jobs[i] != -1)
	++i;
      if (i > 0)
	save = jobs[i - 1];
      else
	save = jobs[i];
      return (save);
    }
  jobs = update_jobs(jobs, 0);
  jobs = realloc_jobs(jobs, nb);
  update_jobs(jobs, 1);
  return (0);
}

int		save_pid(int act, int pid)
{
  static int	my_pid = -1;
  int		*jobs;
  int		i;

  if (act == 1)
    my_jobs(1, my_pid);
  else if (act == 2)
    {
      i = 0;
      jobs = NULL;
      jobs = update_jobs(jobs, 0);
      while (jobs[i] != -1)
	++i;
      if (i > 0 && jobs[i - 1] != my_pid && my_pid != -1)
	my_jobs(1, my_pid);
    }
  else if (act == 3)
    return (my_pid);
  else
    my_pid = pid;
  return (-1);
}

int		*action(int *jobs, int i, int status)
{
  int		past;

  past = 0;
  jobs = update_jobs(jobs, 0);
  i = 0;
  while (jobs[i] != -1)
    ++i;
  if (i > 0)
    --i;
  while (i >= 0 && past == 0)
    {
      if (jobs[i] == -1 || kill(jobs[i], SIGCONT) == -1)
	{
	  jobs[i] = -1;
	  --i;
	}
      else
	++past;
    }
  if (i >= 0)
    waitpid(jobs[i], &status, WUNTRACED);
  if (jobs[0] == -1)
    printf("No more jobs\n");
  return (jobs);
}

int		*update_jobs(int *tmp, int choice)
{
  static int	*jobs = NULL;

  if (choice == 0)
    return (jobs);
  jobs = tmp;
  return (jobs);
}
