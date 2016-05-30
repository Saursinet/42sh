/*
** my_execution.c for minishell2 in /home/saursf/rendu/PSU_2014_minishell2
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Mar  7 00:37:08 2015 Florian Saurs
** Last update Sun May 31 18:07:02 2015 guillaume wilmot
*/

#include "minishell.h"
#include "edit.h"

int	my_exec(char *arg, char **env, char **tabl)
{
  char	*folder;

  if (check_buff(arg) == 0)
    return (check_builts(arg, tabl, env));
  else if (access(arg, 0) != -1 && (folder = get_folder(arg)) != NULL)
    {
      free(folder);
      return (exec_that(arg, tabl, env));
    }
  else
    {
      printf("%s : Command not found.\n", arg);
      return (-1);
    }
}

int	my_exec_complete(char *arg, char **env, char **el_camino)
{
  char	**tabl;

  if (!arg || !arg[0])
    return (-1);
  if (check_pipe(arg) != -1)
    return (call_my_pipe(arg, env, el_camino));
  else
    {
      tabl = my_str_to_wordtab(arg);
      if (check_exist(el_camino, my_str_to_wordtab(arg)) == NULL)
	return (my_exec(arg, env, tabl));
      else
	return (exec_that(check_exist(el_camino,
				      my_str_to_wordtab(arg)), tabl, env));
    }
  return (0);
}

int	check_return_value(char **arg, char **env, char **el_camino)
{
  int	i;
  int	status;

  i = 0;
  while (arg[i] != NULL && my_strncmp("exit", arg[i], 3)
	 && update_fils(0, -1) != -1)
    {
      if (arg[i][0] == ';' || match(arg[i], "||") || match(arg[i], "&&"))
	++i;
      status = my_exec_complete(arg[i++], env, el_camino);
      if (status == -1 && arg[i] && my_strcmp(arg[i], "&&") == 0)
	{
	  while (arg[i] && !match(arg[i], ";") && !match(arg[i], "||"))
	    ++i;
	}
      else if (status == 0 && arg[i] && my_strcmp(arg[i], "||") == 0)
	{
	  while (arg[i] && !match(arg[i], ";") && !match(arg[i], "&&"))
	    ++i;
	}
      else if (arg[i] && arg[i + 1])
	i += 1;
    }
  check_exit(arg, i, status);
  return (0);
}

char	**parse_it(char *s)
{
  char	**arg;
  int	i;
  int	j;

  if ((arg = malloc((my_strlen(s) + 2) * sizeof(char *))) == NULL)
    return (NULL);
  if ((arg[0] = malloc((my_strlen(s) + 2) * sizeof(char))) == NULL)
    return (NULL);
  arg = wordtab_pars(s, arg, 0, 0);
  i = 0;
  while (arg[i])
    {
      j = 0;
      if (arg[i][j] == ' ')
	arg[i] = &arg[i][1];
      if (arg[i] && match(arg[i], "") && !arg[i + 1])
	arg[i] = NULL;
      ++i;
    }
  return (arg);
}

void	wait_to_react(char *s)
{
  int	backs[2];
  char	**arg;
  char	*my_src;
  char	**el_camino;
  char	**env;

  if ((backs[0] = dup(0)) == -1 || (backs[1] = dup(1)) == -1)
    {
      my_errors("Could not backup the fds\n", NULL);
      return;
    }
  my_src = NULL;
  env = save_my_env(NULL);
  arg = parse_it(s);
  my_src = find_my_funct(env, my_src);
  el_camino = my_str_to_wordtab(my_src);
  check_return_value(arg, env, el_camino);
  close(0);
  close(1);
  if ((dup2(backs[0], 0)) == -1 || (dup2(backs[1], 1)) == -1)
    {
      my_errors("Could not put the fds back, expect weird behaviours\n", NULL);
      return;
    }
}
