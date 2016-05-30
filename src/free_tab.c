/*
** free_tab.c for 42sh in /home/saursf/rendu/PSU_2014_42sh/saursinet/mini2
**
** Made by Florian Saurs
** Login   <saursf@epitech.net>
**
** Started on  Sun May 24 18:49:55 2015 Florian Saurs
** Last update Sun May 24 18:50:10 2015 Florian Saurs
*/

#include "types.h"

void	free_tab(char **tabl)
{
  int	i;

  i = 0;
  while (tabl && tabl[i] != NULL)
    {
      free(tabl[i]);
      ++i;
    }
  if (tabl)
    free(tabl);
}
