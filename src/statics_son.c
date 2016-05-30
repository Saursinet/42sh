/*
** statics_son.c for statics_son in /home/wilmot_g/.ssh/PSU_2014_42sh/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 30 23:37:29 2015 guillaume wilmot
** Last update Sun May 31 00:49:59 2015 guillaume wilmot
*/

int		update_fils(int i, int force)
{
  static int	tmp = 0;

  if (i == -1)
    tmp = -1;
  if (force == 0)
    return (0);
  return (tmp);
}
