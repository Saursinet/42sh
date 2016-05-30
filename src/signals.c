/*
** signals.c for signals in /home/wilmot_g/minishell
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun Feb  1 14:45:14 2015 guillaume wilmot
** Last update Sun May 31 17:14:15 2015 Florian Saurs
*/

#include "edit.h"

int	my_putchar_int(int c)
{
  my_putchar(c);
  return (0);
}

void	prompt_sig()
{

}

char	*get_signal()
{
  if (signal(SIGINT, prompt_sig) == SIG_ERR)
    return (my_errors("Signal : error\n", NULL));
  if (signal(SIGTSTP, &ctrl_z) == SIG_ERR)
    return (my_errors("Signal : error\n", NULL));
  return (NULL);
}
