/*
** auto_completion.c for auto_completion in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sun May 10 12:44:32 2015 guillaume wilmot
** Last update Fri May 22 22:06:29 2015 guillaume wilmot
*/

#include "edit.h"

int		check_struct(t_edit **edit, char *tmp, char *term)
{
  char		*match;
  char		**matchs;
  char		*folder;
  char		*command;

  match = NULL;
  matchs = NULL;
  if ((folder = get_folder_for_comp(tmp)) != NULL &&
      (command = get_command_for_comp(tmp)) != NULL)
    {
      if ((match = check_single_match(folder, command)) == NULL)
	if ((match = check_other_match(folder, command)) == NULL)
	  if ((matchs = get_multi_match(folder, command, 0)) == NULL)
	    return (0);
      if (matchs != NULL)
	return (show_multi_match(matchs, folder, edit, term));
      else if (match != NULL)
	return (complete(edit, match));
    }
  else
    my_errors("Could not get folder\n", NULL);
  return (0);
}

int		check_struct_bin(t_edit **edit, char *tmp,
				 char **paths, char *term)
{
  char		*match;
  char		**matchs;

  matchs = NULL;
  match = NULL;
  if (check_for_char(tmp, '/'))
    return (check_struct(edit, tmp, term));
  if ((match = check_single_match_multi(paths, tmp, 0, 0)) == NULL)
    if ((match = check_other_match_multi(paths, tmp)) == NULL)
      matchs = get_multi_match_multi(paths, tmp, 0, 0);
  if (match != NULL)
    return (complete(edit, match));
  else if (matchs != NULL)
    return (show_multi_match(matchs, "/bin", edit, term));
  else
    return (check_struct(edit, tmp, term));
  return (0);
}

int		auto_comp(t_edit **edit, t_cmd *cmd, char **paths, int i)
{
  static char	*prev = NULL;
  char		*tmp;
  char		*full;

  if (cmd->buf_nbr == 9)
    if ((full = take_cmd(*edit, 0, 0)) != NULL)
      if ((tmp = take_cmd_comp(*edit)) != NULL)
	{
	  my_putchar('\n');
	  if (match(tmp, prev))
	    i = start_auto(paths, full, tmp, edit);
	  else
	    {
	      if (!check_for_char(full, ' ') && tmp[0])
		i = check_struct_bin(edit, tmp, paths, get_term(NULL));
	      else if (check_for_char(full, ' '))
		i = check_struct(edit, tmp, get_term(NULL));
	    }
	  my_free(prev);
	  my_free(full);
	  prev = tmp;
	  return (i);
	}
  return (0);
}
