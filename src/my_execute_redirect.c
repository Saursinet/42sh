/*
** my_execute_redirect.c for minishell2 in /home/saursf/rendu/PSU_2014_minishell2
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Fri Mar  6 23:40:54 2015 Florian Saurs
** Last update Sun May 31 18:56:10 2015 guillaume wilmot
*/

#include "minishell.h"

int	redirs_next(t_param *par, char **arg, int i)
{
  if (arg[i + 1] != NULL && arg[i + 1][0] == '>' &&
      arg[i + 1][1] == '>')
    {
      par->no = 1;
      rig_d(arg, i);
      i += 2;
    }
  else if (arg[i + 1] != NULL && arg[i + 1][0] == '<' &&
	   arg[i + 1][1] == 0)
    {
      par->no_bis = 1;
      left_simple(arg, i);
      i += 2;
    }
  else if (arg[i + 1] != NULL && arg[i + 1][0] == '<' &&
	   arg[i + 1][1] == '<')
    {
      par->no_bis = 1;
      my_redir_double_left(arg, i, par);
      i += 2;
    }
  else if (arg[i + 1] != NULL)
    i++;
  return (i);
}

int	do_redirs(t_param *par, char **arg)
{
  int	i;

  i = par->i;
  while (arg[i] && arg[i + 1] && (arg[i + 1][0] == '>' ||
					    arg[i + 1][0] == '<'))
    {
      if (arg[i + 1] != NULL && arg[i + 1][0] == '>' &&
	  arg[i + 1][1] == 0)
	{
	  rig_s(arg, i);
	  par->no = 1;
	  i += 2;
	}
      i = redirs_next(par, arg, i);
    }
  return (i - par->i);
}

int	call_my_red(t_param *par, char **env, char **el_camino, char **arg)
{
  par->no = ((par->action = 0) == 0) ? 0 : 0;
  par->no_bis = ((par->advance = 0) == 0) ? 0 : 0;
  if (arg[par->i + 1] != NULL && (arg[par->i + 1][0] == '>' ||
				  arg[par->i + 1][0] == '<'))
    par->advance = do_redirs(par, arg);
  if (arg[par->i + par->advance + 1] != NULL &&
      arg[par->i + par->advance + 1][0] == '|')
    {
      par->stock_bak = par->stock;
      par->stock = put_father(par, arg, el_camino, env);
      if (par->i != 0 && par->stock_bak != 0 && par->stock_bak != 1)
	close(par->stock_bak);
      ++par->action;
      par->i += par->advance;
    }
  else if (par->action == 0)
    {
      if ((par->stock = put_father(par, arg, el_camino, env)) == -1)
	return (-1);
      close(par->stock);
      return (((par->i = par->i + par->advance) != -42) ? 1 : 1);
    }
  if (arg[par->i] && arg[par->i + 1])
    par->i += 2;
  return (0);
}

int		call_my_pipe(char *s, char **env, char **el_camino)
{
  char		**arg;
  t_param	par;
  int		ok;

  if ((par.backs[0] = dup(0)) == -1 || (par.backs[1] = dup(1)) == -1)
    return (my_int_errors("Could not backup the fds\n", -1));
  arg = my_wordfortab(s);
  if (check_exist(el_camino, my_str_to_wordtab(arg[0])) == NULL)
    {
      printf("%s : Command not found.\n", s);
      return (-1);
    }
  par.i = 0;
  par.stock = 0;
  while (arg[par.i] != NULL && (ok = call_my_red(&par, env, el_camino, arg)) !=
	 1 && ok != -1 && update_fils(0, -1) != -1)
    reback_my_dup(par.backs);
  if ((dup2(par.backs[0], 0)) == -1 || (dup2(par.backs[1], 1)) == -1)
    return (my_int_errors
	    ("Could not put the fds back, expect weird behaviours\n", -1));
  return ((update_fils(0, -1) == -1 || ok == -1) ? -1 : 0);
}
