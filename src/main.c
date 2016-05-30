/*
** main.c for main in /home/wilmot_g/.ssh/PSU_2014_42sh/saursinet/mini2/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 24 19:56:21 2015 guillaume wilmot
** Last update Sun May 31 17:14:50 2015 Florian Saurs
*/

#include "minishell.h"

char		**get_paths()
{
  char          **paths;
  char		*src;

  src = find_my_funct(save_my_env(NULL), NULL);
  paths = my_str_to_wordtab(src);
  return (paths);
}

void		init_env(char **env, char ***my_env)
{
  *my_env = past_my_env(env);
  save_my_env(*my_env);
  create_42shrc(*my_env);
}

void		end_shell(t_hist *history, char *term)
{
  my_final_free(NULL, NULL, NULL, history);
  set_visibility_cursor(term, 1);
  set_canon(0);
}

void		end_main(t_main *s)
{
  if ((s->cmd = get_cmd(&(s->history), s->term, &(s->stop), s->paths)) != NULL)
    {
      if (s->stop == 0 && s->cmd != NULL && s->cmd[0] &&
	  (s->cmd = my_epur(s->cmd))
	  != NULL)
	globbing_and_such(&(s->cmd), &(s->history), s->my_env, s->paths);
      if (isatty(0) && (s->cmd == NULL || (s->cmd != NULL && !s->cmd[0])))
	my_putchar('\n');
      my_free(s->cmd);
    }
  else if (isatty(0) && (s->cmd == NULL || s->cmd[0] == '\0'))
    {
      my_free(s->cmd);
      my_putchar('\n');
    }
  free_double_tab(s->paths);
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  t_main	s;
  int		*jobs;

  if ((jobs = malloc(1 * sizeof(int))) == NULL)
    return (-1);
  jobs[0] = -1;
  jobs = update_jobs(jobs, 1);
  init_env(env, &s.my_env);
  init_history(&s.cmd, &s.history, &s.term, &s.stop);
  while (!s.stop && get_return_value(0, 0, 0, 0) == 0
	 && update_fils(0, -1) != -1)
    {
      save_pid(2, 0);
      get_signal();
      if ((s.paths = get_paths()) != NULL)
	end_main(&s);
      is_too_much(0);
    }
  end_shell(s.history, s.term);
  save_pid(2, 0);
  close_fg(jobs, 0);
  return (get_return_value(0, 0, 0, 1));
}
