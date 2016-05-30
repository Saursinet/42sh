/*
** echo.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/saursinet/42
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Fri May 22 16:19:28 2015 Florian Saurs
** Last update Sun May 31 23:30:40 2015 guillaume wilmot
*/

#include "minishell.h"

int	next_spec_put(char *str, int i, char *car, char *rpl)
{
  if (str[i] == '$' && str[i + 1] && str[i + 1] != ' ')
    i += check_env(str, i + 1);
  else if (str[i] == '\\')
    {
      i = put_spec_car(str, i, car, rpl);
      if (str[i + 1] == '0')
	i += my_getnbr_base(str, i + 2, "01234567", 3);
      else if (str[i + 1] == 'x')
	i += my_getnbr_base(str, i + 2, "0123456789ABCDEF", 2);
      else
	my_putchar(str[i++]);
    }
  else
    my_putchar(str[i++]);
  return (i);
}

void	special_put(char *str)
{
  int	i;
  char	*car;
  char	*rpl;

  car = "abtnvfr";
  rpl = "\a\b\t\n\v\f\r";
  i = 0;
  while (str[i])
    {
      if (i == 0 && str[i] == '\"' && str[strlen(str) - 1] == '\"')
	++i;
      else if (i == (int)strlen(str) - 1 && str[i] == '\"' && str[0] == '\"')
	++i;
      else
	i = next_spec_put(str, i, car, rpl);
    }
}

void	my_put_str(char	*str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (i == 0 && str[i] == '\"' && str[strlen(str)] == '\"')
	++i;
      if (i != (int)strlen(str) && str[i] == '\"')
	++i;
      else
	{
	  if (str[i] == '$' && str[i + 1] && str[i + 1] != ' ')
	    i += check_env(str, i + 1);
	  my_putchar(str[i++]);
	}
    }
}

int	print_echo(char **tabl, int i, int special, int back)
{
  while (tabl[i][0] == '-' && check_more_opt(tabl, i, &special, &back) != 0)
    i += check_more_opt(tabl, i, &special, &back);
  while (tabl[i])
    {
      if (special == 1)
	my_put_str(tabl[i++]);
      else
	special_put(tabl[i++]);
      if (tabl[i])
	my_putchar(' ');
    }
  if (back == 0)
    my_putchar('\n');
  return (0);
}

int	my_echo(char **tabl, int past, int back)
{
  int	i;
  int	special;

  i = -1;
  special = 0;
  while (tabl[++i] && (my_strcmp(tabl[i], "-e") == 0 ||
		      my_strcmp(tabl[i], "-E") == 0 ||
		      my_strcmp(tabl[i], "-n") == 0))
    {
      if (my_strcmp(tabl[i], "-E") == 0 && past == 0)
	{
	  past = 1;
	  special = 1;
	}
      if (my_strcmp(tabl[i], "-e") == 0)
	{
	  ++past;
	  special = 0;
	}
      my_strcmp(tabl[i], "-n") == 0 ? ++back : 0;
    }
  return (print_echo(tabl, i, special, back));
}
