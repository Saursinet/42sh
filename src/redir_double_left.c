/*
** redir.c for redir in /home/wilmot_g/minishell2
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat Feb 21 15:24:10 2015 guillaume wilmot
** Last update Sun May 31 16:21:19 2015 guillaume wilmot
*/

#include "minishell.h"

char	*my_realloc(char *str, int i)
{
  char  *new_str;
  int   b;

  b = 0;
  if (!str || (new_str = malloc(i + 22)) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (b < i)
    {
      new_str[b] = str[b];
      b = b + 1;
    }
  new_str[b] = '\0';
  free(str);
  return (new_str);
}

char	*add_new_line(char *str)
{
  int	i;
  char	*new_str;

  i = 0;
  if ((new_str = malloc((my_strlen(str) + 3) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\n';
  new_str[i + 1] = '\0';
  free(str);
  return (new_str);
}

void	init_redir(int *memory, char **buf, char **buffed)
{
  *memory = 20;
  if (((*buf) = malloc(1025 * sizeof(char))) == NULL)
    my_errors("Malloc : error\n", NULL);
  if (((*buffed) = malloc(22 * sizeof(char))) == NULL)
    my_errors("Malloc : error\n", NULL);
  (*buf)[0] = '\0';
}

char	*get_buf_redir(int j, int i, int ret, char *end)
{
  int	memory;
  char	*buffed;
  char	*buf;

  init_redir(&memory, &buf, &buffed);
  while (match(buf, end) != 1)
    {
      j = 0;
      my_putstr(">> ");
      while (j < ret)
	{
	  if (i >= memory)
	    {
	      buffed = my_realloc(buffed, memory);
	      memory = memory + 20;
	    }
	  buffed[i++] = buf[j++];
	}
      buffed[i] = '\0';
      if (!buf || (ret = read(0, buf, 1024)) == -1)
	return (my_errors("Read : error\n", NULL));
      buf[ret] = '\0';
    }
  free(buf);
  return (buffed);
}

int	my_redir_double_left(char **args, int i, t_param *par)
{
  int	pipefd[2];
  int	back;
  char	*buf;

  if (!args[i + 2])
    return (0);
  back = dup(1);
  if (dup2(par->backs[0], 0) == -1 || dup2(par->backs[1], 1) == -1)
    my_errors("Dup2 : error\n", NULL);
  buf = get_buf_redir(0, 0, 0, add_new_line(args[i + 2]));
  if (pipe(pipefd) == -1)
    my_errors("Pipe : error\n", NULL);
  write(pipefd[1], buf, my_strlen(buf));
  if (close(pipefd[1]) == -1)
    my_errors("Close : error\n", NULL);
  if (dup2(pipefd[0], 0) == -1 || dup2(back, 1) == -1)
    my_errors("Dup2 : error\n", NULL);
  free(buf);
  return (0);
}
