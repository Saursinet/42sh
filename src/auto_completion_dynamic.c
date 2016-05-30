/*
** auto_completion_dynamic.c for auto_completion_dynamic in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 11 20:44:30 2015 guillaume wilmot
** Last update Sun May 24 18:09:47 2015 guillaume wilmot
*/

#include "edit.h"

int	start_dynamic(char **matchs, t_edit **edit, char *folder, char *full)
{
  char	*command;
  char	*str;

  if (match(folder, "./"))
    if (!check_for_char(full, ' '))
      {
	free(folder);
	folder = my_strdup("/bin");
      }
  matchs = del_duplicates(matchs);
  if ((command = take_cmd(*edit, 0, 0)) == NULL)
    return (0);
  str = selectt(matchs, get_term(NULL), command, folder);
  if (str != NULL)
    {
      complete(edit, str);
      free(str);
      free(command);
      free(folder);
      return (2);
    }
  return (2);
}

int	start_auto(char	**paths, char *full, char *tmp, t_edit **edit)
{
  char	**matchs;
  char  *folder;
  char  *command;
  int	i;

  matchs = NULL;
  if ((folder = get_folder_for_comp(tmp)) != NULL &&
      (command = get_command_for_comp(tmp)) != NULL)
    {
      if (!check_for_char(full, ' ') && tmp[0] && !check_for_char(tmp, '/'))
	matchs = get_multi_match_multi(paths, tmp, 0, 0);
      else if (check_for_char(full, ' ') || check_for_char(tmp, '/'))
	matchs = get_multi_match(folder, command, 0);
      my_putstr(tmp);
    }
  if (matchs != NULL)
    {
      i = 0;
      while (matchs[i])
	i++;
      if (i != 1 || (i == 1 && !match(tmp, matchs[0])))
	return (start_dynamic(matchs, edit, folder, full));
    }
  return (0);
}

void	*reset_pos(char *term, char **pos, t_edit *edit, int i)
{
  char	*str;
  char  *term_buffer;

  if (i == 3)
    {
      set_position(*pos, term);
      my_show_s_edit(edit, term);
    }
  else
    {
      term_buffer = NULL;
      if (tgetent(term_buffer, term) != 1)
	return (my_errors("\nTgetent : error\n", NULL));
      if ((str = tgetstr("cm", NULL)) == NULL)
	return (my_errors("Tgetstr : error\n", NULL));
      if (i == 2)
	my_clear(term);
      else if (i == 1)
	tputs(tgoto(str, 0, 0), 1, &my_putchar_int);
      prompt(NULL);
      if ((*pos = get_position(term)) == NULL)
	return (NULL);
      my_show_s_edit(edit, term);
    }
  return ("Ok");
}
