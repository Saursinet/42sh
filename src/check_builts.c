/*
** check_builts.c for 42sh in /home/saursf/42/src
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Fri May 22 14:26:30 2015 Florian Saurs
** Last update Sun May 31 23:28:27 2015 guillaume wilmot
*/

#include "minishell.h"

int		my_history()
{
  t_hist	*hist;
  char		*s;

  hist = get_hist(NULL);
  if (hist == NULL)
    return (1);
  while (hist->prev != NULL)
     hist = hist->prev;
  if (hist->next != NULL)
    hist = hist->next;
  else
    return (0);
  while (hist != NULL)
    {
      my_putstr((s = take_cmd(hist->edit, 0, 0)));
      free(s);
      my_putchar('\n');
      hist = hist->next;
    }
  return (1);
}

int	check_again(UNUSED char *cmd, char **arg, UNUSED char **env)
{
  int	ret;
  int	*jobs;

  jobs = NULL;
  ret = 0;
  if (my_strcmp("fg", arg[0]) == 0)
    {
      jobs = update_jobs(jobs, 0);
      action(jobs, 0, 0);
      ++ret;
    }
  if (my_strcmp("env", arg[0]) == 0)
    {
      print_env(save_my_env(NULL));
      ++ret;
    }
  return (ret);
}

int	check_next(char *cmd, char **arg, char **env)
{
  int	ret;

  ret = 0;
  if (my_strcmp("echo", arg[0]) == 0)
    {
      if (arg[1] == NULL)
	printf("Usage : echo [-neE] [VALUE] \n");
      else
	my_echo(&arg[1], 0, 0);
      ++ret;
    }
  if (my_strcmp("cd", arg[0]) == 0)
    {
      change_directory(arg[1], env);
      ++ret;
    }
  if (my_strcmp("history", cmd) == 0)
    {
      my_history();
      ++ret;
    }
  ret += check_again(cmd, arg, env);
  return (ret);
}

int	check_builts(char *cmd, char **arg, char **env)
{
  int	ret;

  ret = 0;
  if (my_strcmp("setenv", arg[0]) == 0)
    {
      if (arg == NULL || arg[0] == NULL || arg[1] == NULL || arg[2] == NULL)
	printf("Usage : setenv [NAME] [VALUE] \n");
      else
	my_setenv(env, arg[1], arg[2]);
      ++ret;
    }
  if (my_strcmp("unsetenv", arg[0]) == 0)
    {
      if (arg && arg[0] && arg[1])
	my_unsetenv(env, arg[1]);
      else
	printf("Usage : unsetenv [NAME] \n");
      save_my_env(env);
      ++ret;
    }
  ret += check_next(cmd, arg, env);
  if (ret == 0)
    printf("%s : Command not found\n", arg[0]);
  return (ret);
}
