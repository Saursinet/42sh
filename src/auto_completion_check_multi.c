/*
** auto_completion_check_multi.c for auto_completion_check_multi in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue May 12 13:53:09 2015 guillaume wilmot
** Last update Sun May 31 17:55:04 2015 guillaume wilmot
*/

#include "edit.h"

char		*check_special_single_match_multi(char **folder, char *to_find,
						  int i, int nbr)
{
  DIR		*dir;
  char		*match;
  struct dirent	*dirent;

  nbr = 0;
  i = 0;
  while (folder[i])
    {
      if ((dir = opendir(folder[i++])) == NULL)
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
    }
  return ((nbr == 1) ? match : NULL);
}

char		*check_single_match_multi(char **folder, char *to_find,
					  int i, int nbr)
{
  char		*matchs;
  DIR		*dir;
  struct dirent	*dirent;

  matchs = NULL;
  while (folder[i])
    {
      if ((dir = opendir(folder[i++])) != NULL)
	{
	  while ((dirent = readdir(dir)) != NULL)
	    {
	      if (beggin_match(dirent->d_name, to_find))
		{
		  if (!match(matchs, dirent->d_name))
		    nbr++;
		  if ((matchs = my_strdup(dirent->d_name)) == NULL)
		    return (my_errors("Strdup : error\n", NULL));
		}
	    }
	  if (closedir(dir) != 0)
	    my_errors("Closedir : error\n", NULL);
	}
    }
  return (((nbr == 1) ? matchs :
	   check_special_single_match_multi(folder, to_find, 0, 0)));
}

char		*check_other_match_multi(char **folder, char *to_find)
{
  int           i;
  int           j;
  int           key;
  char          *match;
  char          **matchs;

  if ((matchs = (get_multi_match_multi(folder, to_find, 1, 0))) == NULL)
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
  return ((i <= my_strlen(to_find)) ? NULL : match);
}

char		**get_special_multi_match_multi(char **folder, char *to_find,
						int i, int j)
{
  char          **match;
  DIR           *dir;
  struct dirent *dirent;

  match = NULL;
  while (folder[j])
    {
      if ((dir = opendir(folder[j++])) != NULL)
	{
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
	}
    }
  return (match);
}

char		**get_multi_match_multi(char **folder, char *to_find,
					int strict, int i)
{
  int		j;
  char          **match;
  DIR           *dir;
  struct dirent *dirent;

  match = ((j = 0) == 0) ? NULL : NULL;
  while (folder[j])
    {
      if (folder[j] && (dir = opendir(folder[j])) != NULL)
	{
	  while ((dirent = readdir(dir)) != NULL)
	    if (beggin_match(dirent->d_name, to_find))
	      {
		if ((match = my_realloc_double_tab(match, i)) == NULL ||
		    (match[i++] = my_strdup(dirent->d_name)) == NULL)
		  return (my_errors("Malloc : error\n", NULL));
		match[i] = '\0';
	      }
	  if (closedir(dir) != 0)
	    my_errors("Closedir : error\n", NULL);
	}
      j++;
    }
  return ((strict || match != NULL) ? match :
	  get_special_multi_match_multi(folder, to_find, 0, 0));
}
