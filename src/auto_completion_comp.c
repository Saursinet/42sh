/*
** auto_completion_comp.c for auto_completion_comp in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 10 18:01:00 2015 guillaume wilmot
** Last update Sun May 31 15:36:50 2015 Florian Saurs
*/

#include "edit.h"

int		complete(t_edit **edit, char *str)
{
  char		buf[2];
  t_edit	*tmp;
  int		i;

  if ((tmp = *edit) != NULL)
    {
      while (tmp->prev != NULL && tmp->actual != 1)
	tmp = tmp->prev;
      while (tmp->prev != NULL && tmp->prev->c[0] != '/'
	     && tmp->prev->c[0] != ' ')
	delete_actual(*edit, 0);
      i = 0;
      buf[1] = '\0';
      while (str[i])
	{
	  buf[0] = str[i];
	  my_put_in_s_edit(edit, buf);
	  i++;
	}
    }
  return (3);
}

char	**del_duplicates(char **matches)
{
  int	i;
  int	j;

  i = 0;
  while (matches[i])
    {
      if (matches[i])
	j = i + 1;
      else
	return (matches);
      while (matches[j])
	{
	  if (match(matches[i], matches[j]) || matches[j][0] == '.' ||
	      match(matches[j], ".."))
	    while (matches[j])
	      {
		matches[j] = matches[j + 1];
		j++;
	      }
	  if (matches[j])
	    j++;
	}
      i++;
    }
  return (matches);
}

char		*get_color_style(char *path)
{
  struct stat	stats;

  if (access(path, F_OK) == -1 || stat(path, &stats) == -1)
    return (NULL);
  if (S_ISDIR(stats.st_mode))
    return ("\033[01;34m");
  else
    {
      if (S_ISLNK(stats.st_mode))
	return ("\033[01;36m");
      if (access(path, X_OK) != -1)
	return ("\033[0;32m");
    }
  return (NULL);
}

int		show_multi_match(char **matches, char *folder, t_edit **edit,
				 char *term)
{
  char		*command;
  t_list	*list;
  t_tools	tool;

  matches = del_duplicates(matches);
  if ((command = take_cmd(*edit, 0, 0)) != NULL)
    if (my_struct(&tool, term, command, folder) == 0 &&
	(list = init_my_list(matches, tool)) != NULL)
      {
	list->pos = 0;
	my_show_list(list, tool, command);
	free_my_list(list, tool);
	free(command);
      }
  return (1);
}
