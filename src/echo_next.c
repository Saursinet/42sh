/*
** echo_next.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/saursinet/42
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Fri May 22 16:24:10 2015 Florian Saurs
** Last update Sun May 31 21:05:16 2015 Florian Saurs
*/

#include "minishell.h"

int	cmpt_chaine(char *str, int i, int turn)
{
  int	c;
  int	tmp;

  c = 0;
  tmp = i;
  while (str[i] && c < turn && (str[i] >= '0' || str[i] <= '9'))
    {
      ++c;
      ++i;
    }
  return (i - tmp);
}

int	take_cmpt(char *str, int i, int turn, int compteur_base)
{
  int	cmpt;
  int	compteur_chaine;

  compteur_chaine = cmpt_chaine(str, i, turn);
  cmpt = 1;
  while (compteur_chaine > 0)
    {
      cmpt *= compteur_base;
      --compteur_chaine;
    }
  cmpt /= compteur_base;
  return (cmpt);
}

int	my_getnbr_base(char *str, int i, char *base, int turn)
{
  int	compteur_base;
  int	compteur_chaine;
  int	c;
  int	d;
  int	nbr;
  int	cmpt;

  nbr = 0;
  compteur_base = my_strlen(base);
  cmpt = take_cmpt(str, i, turn, compteur_base);
  c = i;
  compteur_chaine = cmpt_chaine(str, i, turn);
  while (compteur_chaine > 0)
    {
      d = 0;
      while (base[d] && str[i] != base[d])
	++d;
      --compteur_chaine;
      nbr = nbr + d * cmpt;
      cmpt /= compteur_base;
      ++i;
    }
  my_putchar(nbr);
  return (cmpt_chaine(str, c, turn) + 2);
}

int	check_more_opt(char **tabl, int i, int *special, int *back)
{
  int	c;

  c = 1;
  while (tabl[i][c])
    {
      if (tabl[i][c] == 'e' || tabl[i][c] == 'E' || tabl[i][c] == 'n')
	++c;
      else
	return (0);
    }
  c = 0;
  while (tabl[i][c])
    {
      if (tabl[i][c] == 'n')
	++*back;
      else if (tabl[i][c] == 'e')
	*special = 0;
      else if (tabl[i][c] == 'E')
	++*special;
      ++c;
    }
  return (1);
}
