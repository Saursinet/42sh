/*
** my_dup.c for minishell2 in /home/saurs_f/rendu/PSU_2014_minishell2
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Feb  4 15:56:14 2015 Florian Saurs
** Last update Sun May 31 19:24:09 2015 guillaume wilmot
*/

#include "minishell.h"

void	reback_my_dup(int back[2])
{
  close(0);
  close(1);
  if (dup2(back[0], 0) == -1)
    my_errors("Could not back the entry\n", NULL);
  if (dup2(back[1], 1) == -1)
    my_errors("Could not back the output\n", NULL);
}

int	check_pipe(char *s)
{
  int	i;

  i = 0;
  while (s[i] != 0)
    {
      if (s[i] == '|')
	return (0);
      else if (s[i] == '>')
	return (1);
      else if (s[i] == '<')
	return (3);
     ++i;
    }
  return (-1);
}

char	**my_linein(char *s, int i, char **arg, char car)
{
  int	tmp;
  int	c;

  tmp = i;
  c = 0;
  while (s[i] != car && s[i] != 0)
    ++i;
  while (arg[c] != NULL)
    ++c;
  if ((arg[c] = malloc((i - tmp + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (s[tmp] == ' ')
    tmp++;
  while (s[tmp] != 0 && s[tmp] != car)
    arg[c][i++] = s[tmp++];
  arg[c][i] = 0;
  arg[c + 1] = NULL;
  return (arg);
}

char	**my_wordintab(char *s, char car)
{
  char	**arg;
  int	i;
  int	c;

  i = 0;
  c = 1;
  while (s[i] != 0)
    {
      if (s[i] == car)
	++c;
      ++i;
    }
  i = 0;
  if ((arg = malloc((c + 1) * sizeof(char *))) == NULL)
    return (NULL);
  arg[0] = NULL;
  while (s[i] != 0)
    {
      arg = my_linein(s, i, arg, car);
      while (s[i] != 0 && s[i] != car)
	++i;
      while (s[i] == car)
	++i;
    }
  return (arg);
}

int	put_father(t_param *par, char **arg, char **el_camino, char **env)
{
  char	**tabl;
  int	pip[2];
  int	pid;
  int	status;

  if (!check_exist(el_camino, my_str_to_wordtab(arg[par->i])) || pipe(pip) < 0)
    return (-1);
  if ((pid = fork()) == 0)
    {
      close(pip[0]);
      if (par->no_bis == 0 && par->i != 0)
	dup2(par->stock, 0);
      if (arg[par->i + par->advance + 1] != NULL && par->no == 0)
	dup2(pip[1], 1);
      tabl = my_str_to_wordtab(arg[par->i]);
      if ((arg[0] = check_exist(el_camino, my_str_to_wordtab(arg[par->i]))))
	execve(arg[0], tabl, env);
      return (update_fils(-1, 0));
    }
  else
    {
      waitpid(pid, &status, WUNTRACED);
      close(pip[1]);
    }
  return (pip[0]);
}
