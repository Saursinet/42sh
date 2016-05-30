/*
** prompt.c for prompt in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May  4 15:27:22 2015 guillaume wilmot
** Last update Sun May 31 18:15:27 2015 guillaume wilmot
*/

#include "edit.h"

char	*cut_actual_folder(char *str)
{
  char  *folder;
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i])
    i = i + 1;
  while (str[i] != '/' && i >= 0)
    i = i - 1;
  if (i == 0 && my_strlen(str) == 2)
    {
      free(str);
      return (my_strdup("/"));
    }
  if ((folder = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", my_strdup("Error")));
  i = i + 1;
  while (i < str[i])
    folder[j++] = str[i++];
  folder[(folder[j - 1] == '\n') ? j - 1 : j] = '\0';
  free(str);
  return (folder);
}

char	*read_actual_folder(int ret, char *buf, int pipefd[2], int i)
{
  close(pipefd[1]);
  waitpid(ret, &ret, WNOHANG);
  if ((buf = malloc(1025 * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", my_strdup("Error")));
  if ((ret = read(pipefd[0], buf, 1024)) == -1)
    return (my_errors("Read : error\n", my_strdup("Error")));
  if (ret == 0)
    {
      free(buf);
      return (my_strdup("NULL\n"));
    }
  buf[ret] = '\0';
  close(pipefd[0]);
  if (i == 0)
    return (cut_actual_folder(buf));
  else
    return (buf);
}

char	*get_actual_folder(int i)
{
  int   pipefd[2];
  int   ret;
  char  *buf;
  char	*arg[2];

  buf = NULL;
  if ((pipe(pipefd)) == -1)
    return (my_errors("Pipe : error\n", my_strdup("Error")));
  if ((ret = fork()) == -1)
    return (my_errors("fork : error\n", my_strdup("Error")));
  if (ret != 0)
    return (read_actual_folder(ret, buf, pipefd, i));
  if (dup2(pipefd[1], 1) == -1)
    my_errors("Dup2 : error\n", NULL);
  arg[0] = "/bin/pwd";
  arg[1] = NULL;
  execve("/bin/pwd", arg, save_my_env(NULL));
  close(pipefd[1]);
  close(pipefd[0]);
  my_errors("Execve : error, could not get folder", NULL);
  update_fils(-1, 0);
  return (NULL);
}

char		*update_prompt(char **env)
{
  char		*prompt;
  char		*fri;
  char		*s;
  static int	i = 0;

  prompt = concatenate("(\033[31m", get_user(env, NULL), 0);
  fri = concatenate(prompt, "\033[0m, n° \033[32m", 0);
  my_free(prompt);
  prompt = concatenate(fri, itos(i++), 0);
  my_free(fri);
  fri = concatenate(prompt, "\033[0m) [\033[36m", 0);
  my_free(prompt);
  if ((s = get_actual_folder(0)) == NULL)
    return (NULL);
  prompt = concatenate(fri, (match(s, "NULL\n")) ? "Unknown" : s, 0);
  my_free(fri);
  my_free(s);
  prompt = concatenate(prompt, "\033[0m] >", 0);
  return ((prompt == NULL) ? my_strdup("Prompt >") : prompt);
}

int		prompt(char **env)
{
  static char	*prompt = "$> ";

  if (env != NULL)
    if ((prompt = update_prompt(env)) == NULL)
      return (-1);
  if (prompt != NULL)
    my_putstr(prompt);
  else
    {
      prompt = "$> ";
      my_putstr(prompt);
    }
  return (0);
}
