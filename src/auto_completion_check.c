/*
** auto_completion_check.c for auto_completion_check in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 11 20:20:08 2015 guillaume wilmot
** Last update Fri May 15 19:02:01 2015 guillaume wilmot
*/

#include "edit.h"

char		*check_special_single_match(char *folder, char *to_find)
{
  DIR		*dir;
  char		*match;
  int		nbr;
  struct dirent *dirent;

  nbr = 0;
  if ((dir = opendir(folder)) == NULL)
    return (NULL);
  while ((dirent = readdir(dir)) != NULL)
    {
      if (hidden_match(dirent->d_name, to_find))
	{
	  if ((match = my_strdup(dirent->d_name)) == NULL)
	    return (my_errors("Strdup : error\n", NULL));
	  nbr++;
	}
    }
  if (closedir(dir) != 0)
    my_errors("Closedir : error\n", NULL);
  return ((nbr == 1) ? match : NULL);
}

char		*check_single_match(char *folder, char *to_find)
{
  char		*match;
  DIR		*dir;
  int		nbr;
  struct dirent *dirent;

  nbr = 0;
  match = NULL;
  if ((dir = opendir(folder)) == NULL)
    return (NULL);
  while ((dirent = readdir(dir)) != NULL)
    {
      if (beggin_match(dirent->d_name, to_find))
	{
	  if ((match = my_strdup(dirent->d_name)) == NULL)
	    return (my_errors("Strdup : error\n", NULL));
	  nbr++;
	}
    }
  if (closedir(dir) != 0)
    my_errors("Closedir : error\n", NULL);
  return ((nbr == 1) ? match : check_special_single_match
	  (folder, to_find));
}

char		*check_other_match(char *folder, char *to_find)
{
  int		i;
  int		j;
  int		key;
  char		*match;
  char		**matchs;

  if ((matchs = (get_multi_match(folder, to_find, 1))) == NULL)
    return (NULL);
  if ((match = malloc((biggest_in_tab(matchs) + 5) * sizeof(char))) == NULL)
    return (my_errors("Malloc : error\n", NULL));
  i = 0;
  key = 0;
  while (!key)
    {
      j = 0;
      while (matchs[j] && matchs[j][i] == matchs[0][i])
	j++;
      key = (matchs[j]) ? 1 : 0;
      match[i] = (matchs[j]) ? '\0' : matchs[0][i];
      i = (matchs[j]) ? i : i + 1;
    }
  return (((i <= my_strlen(to_find)) ? NULL : match));
}

char		**get_special_multi_match(char *folder, char *to_find)
{
  int		i;
  char		**match;
  DIR		*dir;
  struct dirent *dirent;

  i = 0;
  match = NULL;
  if ((dir = opendir(folder)) == NULL)
    return (NULL);
  while ((dirent = readdir(dir)) != NULL)
    {
      if (hidden_match(dirent->d_name, to_find))
	{
	  if ((match = my_realloc_double_tab(match, i)) == NULL)
	    return (my_errors("Malloc : error\n", NULL));
	  if ((match[i++] = my_strdup(dirent->d_name)) == NULL)
	    return (my_errors("Strdup : error\n", NULL));
	  match[i] = '\0';
	}
    }
  if (closedir(dir) != 0)
    my_errors("Closedir : error\n", NULL);
  return (match);
}

char		**get_multi_match(char *folder, char *to_find, int strict)
{
  int		i;
  char		**match;
  DIR		*dir;
  struct dirent *dirent;

  i = 0;
  match = NULL;
  if ((dir = opendir(folder)) == NULL)
    return (NULL);
  while ((dirent = readdir(dir)) != NULL)
    {
      if (beggin_match(dirent->d_name, to_find))
	{
	  if ((match = my_realloc_double_tab(match, i)) == NULL)
	    return (my_errors("Malloc : error\n", NULL));
	  if ((match[i++] = my_strdup(dirent->d_name)) == NULL)
	    return (my_errors("Strdup : error\n", NULL));
	  match[i] = '\0';
	}
    }
  if (closedir(dir) != 0)
    my_errors("Closedir : error\n", NULL);
  if (strict)
    return (match);
  return ((match == NULL) ? get_special_multi_match(folder, to_find) : match);
}
