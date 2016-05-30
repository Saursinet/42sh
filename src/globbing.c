/*
** globbing.c for globbing in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 23 15:22:06 2015 guillaume wilmot
** Last update Sun May 31 23:24:45 2015 Kévin Empociello
*/

#include "edit.h"

char	*glob_this(char *str)
{
  glob_t globbuf;

  if ((glob(str, GLOB_TILDE_CHECK | GLOB_MARK, NULL, &globbuf)) != 0)
    return (str);
  free(str);
  return (concat_tab(globbuf.gl_pathv));
}

int	len_env(char **env)
{
  int	i;

  i = 0;
  while (env && env[i] != NULL)
    i++;
  return (i);
}

void	globbing_and_such(char **cmd, t_hist **hist, char **env, char **path)
{
  char	*pos;

  pos = get_position(get_term(NULL));
  replace_history_aliases(cmd, hist);
  *cmd = check_alias(*cmd, env);
  if (isatty(0) && !is_too_much(-1) && (len_env(env) > 5))
    *cmd = levenshtein(*cmd, env);
  set_position(pos, get_term(NULL));
  if (isatty(0))
    my_putstr(*cmd);
  globbing(cmd);
  if (isatty(0))
    my_putchar('\n');
  get_hist(*hist);
  if (check_syntax(*cmd, path) == 1)
    wait_to_react(*cmd);
}

void	globbing(char **cmd)
{
  char	**tabl;
  int	i;

  if ((tabl = str_to_word_tab(*cmd)) != NULL && tabl[0])
    {
      i = 0;
      while (tabl[i])
	{
	  while (tabl[i] && (tabl[i][0] == '|' || tabl[i][0] == ';' ||
			     tabl[i][0] == '`' || tabl[i][0] == '&' ||
			     tabl[i][0] == '<' || tabl[i][0] == '>' ||
			     tabl[i][0] == '-'))
	    i++;
	  tabl[i] = glob_this(tabl[i]);
	  if (tabl[i])
	    i++;
	}
      free(*cmd);
      *cmd = concat_tab(tabl);
    }
}
