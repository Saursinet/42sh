/*
** echo_end.c for echo_end in /home/wilmot_g/.ssh/PSU_2014_42sh/saursinet/mini2/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 24 20:54:09 2015 guillaume wilmot
** Last update Sun May 24 21:02:19 2015 guillaume wilmot
*/

#include "minishell.h"

int	put_spec_car(char *str, int i, const char car[8], const char rpl[8])
{
  int	a;

  a = 0;
  while (car[a])
    {
      if (car[a] == str[i + 1])
        {
          my_putchar(rpl[a]);
          i += 2;
        }
      ++a;
    }
  return (i);
}

int	check_env(char *str, int i)
{
  char	**env;
  int	c;
  int	len;
  int	tmp;

  env = save_my_env(NULL);
  tmp = i;
  while (str[i] && str[i] != ' ')
    ++i;
  len = i - tmp;
  c = 0;
  while (env[c] && my_strncmp(&str[tmp], env[c], len - 1) != 0)
    ++c;
  if (env[c])
    {
      i = 0;
      while (env[c][i++] != '=');
      while (env[c][i])
        my_putchar(env[c][i++]);
    }
  return (len + 1);
}
