/*
** alias.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/42sh/src
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sat May 23 16:51:32 2015 Florian Saurs
** Last update Fri May 29 17:59:58 2015 Florian Saurs
*/

#include "minishell.h"

char		*take_tab(char **arg)
{
  int		length;
  int		i;
  int		j;
  char		*str;

  length = 1;
  i = 0;
  while (arg[i])
    length += my_strlen(arg[i++]);
  if ((str = malloc(length * sizeof(char))) == NULL)
    return (arg[0]);
  i = 0;
  length = 0;
  while (arg[i])
    {
      j = 0;
      while (arg[i][j])
	str[length++] = arg[i][j++];
      ++i;
    }
  str[length] = 0;
  return (str);
}

char		*change_it(char *cmd, int fd)
{
  char		*s;
  char		*dest;
  char		**tabl;
  char		**arg;
  int		i;

  dest = NULL;
  while ((s = get_next_line(fd)))
    dest = my_add(dest, s);
  tabl = my_str_wordtab(dest);
  free(dest);
  arg = wordtab(cmd);
  i = -1;
  while (arg[++i])
    arg[i] = find_it(tabl, arg[i], -1);
  cmd = take_tab(arg);
  i = 0;
  while (tabl[i])
    free(tabl[i++]);
  free(tabl);
  return (cmd);
}

char		*my_concat(char *src, char *dest)
{
  char		*tmp;
  int		length;
  int		i;
  int		j;

  length = my_strlen(src) + my_strlen(dest) + 3;
  if ((tmp = malloc((length * sizeof(char)))) == NULL)
    return (NULL);
  i = -1;
  while (src[++i])
    tmp[i] = src[i];
  tmp[i++] = '/';
  j = 0;
  while (dest[j])
    tmp[i++] = dest[j++];
  tmp[i] = 0;
  return (tmp);
}

char		*take_my_pwd(char *str, char **env)
{
  int		i;

  i = 0;
  while (env && env[i] && my_strncmp(env[i], "PWD", 2) != 0)
    ++i;
  if (env[i] == NULL)
    str = ".42shrc";
  else
    str = my_concat(&env[i][4], ".42shrc");
  return (str);
}

char		*check_alias(char *cmd, UNUSED char **env)
{
  int		fd;
  char		*str = NULL;
  static char	*my_pwd = NULL;

  if (my_pwd == NULL)
    my_pwd = take_my_pwd(my_pwd, save_my_env(NULL));
  if (cmd == NULL)
    return (NULL);
  if ((fd = open(my_pwd, O_RDWR)) != -1)
    {
      str = change_it(cmd, fd);
      close(fd);
    }
  else
    return (cmd);
  return (str);
}
