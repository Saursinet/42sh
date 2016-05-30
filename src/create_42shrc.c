/*
** create_42shrc.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/42sh/src
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sat May 23 17:06:28 2015 Florian Saurs
** Last update Sun May 31 15:37:36 2015 Florian Saurs
*/

#include "minishell.h"

int	execute_cmd(char *str)
{
  int	i;
  int	tmp;
  char	**env;
  char	*s1;
  char	*s2;

  i = 0;
  s1 = NULL;
  s2 = NULL;
  if (my_strncmp("export ", str, 6) != 0)
    return (-1);
  while (str[i] && str[i] != '=')
    ++i;
  if (str[i] == 0 || str[i + 1] == 0)
    return (printf("Wrong import: %s\n", str));
  tmp = i++;
  str[tmp] = 0;
  while (str[i])
    ++i;
  env = save_my_env(NULL);
  s1 = take_my_export_first(str);
  s2 = take_my_export_second(str);
  my_setenv(env, s1, s2);
  return (0);
}

int	parse_now(char **tabl)
{
  int	i;

  i = 0;
  while (tabl[i])
    {
      if (tabl[i][0] != '#' && tabl[i][0] != '\n' && is_alias(tabl[i]) == -1 &&
	  is_export(tabl[i]) == 0)
	execute_cmd(tabl[i]);
      else if (is_alias(tabl[i]) == -1 && tabl[i][0] != '#' &&
	       tabl[i][0] != '\n')
	printf("There is an error in .42shrc : %s\n", tabl[i]);
      ++i;
    }
  return (0);
}

int	check_42shrc(int fd)
{
  char	*s;
  char	*dest;
  char	**tabl;

  dest = NULL;
  while ((s = get_next_line(fd)))
    dest = my_add(dest, s);
  tabl = my_str_wordtab(dest);
  free(dest);
  parse_now(tabl);
  return (0);
}

void	create_42shrc(char **env)
{
  int	fd;
  char	*str;

  fd = 0;
  while (env[fd] && my_strncmp(env[fd], "PWD", 3) != 0)
    ++fd;
  if (env[fd] == NULL)
    str = ".42shrc";
  else
    str = my_concat(&env[fd][4], ".42shrc");
  if ((fd = open(str, O_RDWR)) != -1)
    check_42shrc(fd);
  else
    {
      fd = open(str, O_CREAT | O_RDWR, 0777);
      put_alias(fd);
    }
}
