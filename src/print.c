/*
** print.c for  in /home/barrie_j/Documents/rendu/Sem_2/PSU/PSU_2014_42sh/RedBlackTree
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Sun May  3 21:00:22 2015 Jean BARRIERE
** Last update Sun May  3 21:39:45 2015 Jean BARRIERE
*/

#include "types.h"

int	put_msg_int(int out, char *msg, int ret)
{
  if (msg != NULL)
    write(out, msg, my_strlen(msg));
  return (ret);
}

void	*put_msg_ptr(int out, char *msg, void *ret)
{
  if (msg != NULL)
    write(out, msg, my_strlen(msg));
  return (ret);
}
