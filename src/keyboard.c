/*
** keyboard.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Fri May 22 15:19:35 2015 Kévin Empociello
** Last update Sun May 31 21:16:23 2015 guillaume wilmot
*/

#include "edit.h"

void	init_keyboard(t_keyboard *key)
{
  key->xa = 0;
  key->ya = 0;
  key->xb = 0;
  key->yb = 0;
  key->x = 0;
  key->y = 0;
  key->keyboard[0] = "azertyuiop";
  key->keyboard[1] = "qsdfghjklm";
  key->keyboard[2] = "wxcvbn";
  key->keyboard[3] = NULL;
}

double		keyboard(char a, char b)
{
  t_keyboard	key;

  init_keyboard(&key);
  while (key.keyboard[key.y] != NULL)
    {
      key.x = 0;
      while (key.keyboard[key.y] && key.keyboard[key.y][key.x] != '\0')
	{
	  if (key.keyboard[key.y][key.x] == a)
	    {
	      key.ya = key.y;
	      key.xa = key.x;
	    }
	  if (key.keyboard[key.y][key.x] == b)
	    {
	       key.yb = key.y;
	       key.xb = key.x;
	    }
	  key.x++;
	}
      key.y++;
    }
  return (my_sqrt(((key.xb - key.xa) * (key.xb - key.xa)) +
		  ((key.yb - key.ya) * (key.yb - key.ya)), 3));
}

int		keyboard_distance(char *str1, char *str2)
{
  double	result;
  int		i;

  i = 0;
  result = 0;
  while (str1 && str2 && str1[i] != '\0' && str2[i] != '\0')
    {
      result += (keyboard(str1[i], str2[i]));
      i++;
    }
  return (result);
}

char	*keyboard_precision(char **dic, char *command, int best)
{
  int	a;
  int	word_pos;
  int	word_far;

  word_far = -1;
  word_pos = 0;
  a = 0;
  while (dic[a] != NULL)
    {
      if ((give_distance(dic[a], command)) == best)
	{
	  if (word_far == -1)
	    {
	      word_far = keyboard_distance(dic[a], command);
	      word_pos = a;
	    }
	  if (keyboard_distance(dic[a], command) < word_far)
	    {
	      word_far = keyboard_distance(dic[a], command);
	      word_pos = a;
	    }
	}
      a++;
    }
  return (dic[word_pos]);
}
