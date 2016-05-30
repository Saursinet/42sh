/*
** command_exec.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/saursinet/mini2
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sun May 24 21:48:05 2015 Florian Saurs
** Last update Sun May 31 17:16:06 2015 Florian Saurs
*/

#include "minishell.h"
#include "edit.h"

void	check_wrong_end(int status)
{
  if (WTERMSIG(status) == SIGSEGV)
    printf("Segmentation fault (core dumped)\n");
  (WTERMSIG(status) == SIGQUIT) ? printf("Quit (core dumped)\n") : 0;
  (WTERMSIG(status) == SIGBUS) ? printf("Bus error (core dumped)\n") : 0;
  if (WTERMSIG(status) == SIGFPE)
    printf("Floating point exception (core dumped)\n");
  (WTERMSIG(status) == SIGKILL) ? printf("Killed\n") : 0;
  (WTERMSIG(status) == SIGPIPE) ? printf("Broken pipe\n") : 0;
  if (WTERMSIG(status) == SIGSEGV)
    printf("Segmentation fault (core dumped)\n");
  (WTERMSIG(status) == SIGQUIT) ? printf("Quit (core dumped)\n") : 0;
  (WTERMSIG(status) == SIGBUS) ? printf("Bus error (core dumped)\n") : 0;
  if (WTERMSIG(status) == SIGFPE)
    printf("Floating exception (core dumped)\n");
  (WTERMSIG(status) == SIGKILL) ? printf("Killed\n") : 0;
  if (WTERMSIG(status) == SIGPIPE)
    printf("Broken pipe\n");
}

int	exec_that(char *arg, char **tabl, char **env)
{
  int	pid;
  int	status;

  status = 0;
  pid = fork();
  if (pid == 0)
    {
      signal(SIGTSTP, SIG_DFL);
      execve(arg, tabl, env);
      return (update_fils(-1, 0));
    }
  else
    {
      status = 0;
      save_pid(0, pid);
      waitpid(pid, &status, WUNTRACED);
      check_wrong_end(status);
    }
  return (status);
}

int	place_env(char **env)
{
  int	i;

  i = 0;
  while (env && env[i] != NULL && (strncmp(env[i], "PATH=", 5) != 0))
    i++;
  if (env == NULL || env[i] == NULL || (strncmp(env[i], "PATH=", 5) != 0))
    return (-1);
  return (i);
}

void	init_history(char **cmd, t_hist **hist, char **term, int *stop)
{
  *cmd = NULL;
  *hist = NULL;
  my_put_in_s_hist(hist, root_hist());
  *term = "xterm";
  get_term(*term);
  *stop = 0;
}
