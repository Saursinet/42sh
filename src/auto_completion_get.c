/*
** auto_completion_get.c for auto_completion_get in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 10 17:33:56 2015 guillaume wilmot
** Last update Sun May 31 15:41:53 2015 Florian Saurs
*/

#include "edit.h"

int	check_for_char(char *str, char c)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

char	*get_folder_for_comp(char *str)
{
  char	*folder;
  int	i;
  int	j;

  i = 0;
  while (str[i])
    i++;
  while (i > 0 && str[i] != '/')
    i--;
  if (str[i] != '/')
    return (my_strdup("./"));
  if ((folder = malloc((i + 5) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  j = 0;
  while (j <= i)
    {
      folder[j] = str[j];
      j++;
    }
  folder[j] = '\0';
  return (folder);
}

char	*get_command_for_comp(char *str)
{
  char	*command;
  int	i;
  int	j;

  i = 0;
  while (str[i])
    i++;
  while (i > 0 && str[i] != '/')
    i--;
  if (str[i] != '/')
    return (my_strdup(str));
  i++;
  if ((command = malloc((my_strlen(str) + 5) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  j = 0;
  while (i < my_strlen(str))
    command[j++] = str[i++];
  command[j] = '\0';
  return (command);
}
