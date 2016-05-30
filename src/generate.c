/*
** generate.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Fri May 22 01:32:07 2015 Kévin Empociello
** Last update Sun May 24 02:24:22 2015 guillaume wilmot
*/

#include "edit.h"

int		size_dir(char *direct)
{
  int		i;
  DIR		*d;
  struct dirent	*dir;

  i = 0;
  if (access(direct, R_OK) != 0)
    return (-1);
  d = opendir(direct);
  if (d != NULL)
    while ((dir = readdir(d)) != NULL)
      i++;
  closedir(d);
  return (i);
}

char		**try_extend(char **path, DIR *d, char **new, int i)
{
  struct dirent	*dir;
  if (path != NULL)
    free(path);
  if (d != NULL)
    while ((dir = readdir(d)) != NULL)
      if (strlen(dir->d_name) > 1 && dir->d_name != NULL)
	new[i++] = strdup(dir->d_name);
  new[i] = NULL;
  closedir(d);
  return (new);
}

char		**try_dir(char *direct, char **path)
{
  char		**new;
  DIR		*d;
  int		i;
  int		j;

  i = 0;
  j = 0;
  new = NULL;
  if ((i = size_dir(direct)) == -1)
    return (path);
  d = opendir(direct);
  while (path && path[j] != NULL)
    j++;
  if ((new = malloc((i + j + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (path && path[i] != NULL)
    {
      new[i] = path[i];
      i++;
    }
  new = try_extend(path, d, new, i);
  return (new);
}

char		**gen_path(char **env)
{
  char		*s;
  char		**path;
  int		i;
  char		*tmp;

  i = 0;
  s = NULL;
  path = NULL;
  while (env && env[i] != NULL && (strncmp(env[i], "PATH=", 5) != 0))
    i++;
  if (env == NULL || env[i] == NULL || (strncmp(env[i], "PATH=", 5) != 0))
    return (NULL);
  else
    {
      tmp = cpy(env[i]);
      s = strtok(tmp, ":");
      path = try_dir(s, path);
      while ((s = strtok(NULL, ":")) != NULL)
	path = try_dir(s, path);
      free(tmp);
      return (path);
    }
  return (NULL);
}

char	**gen_data(char **env)
{
  char	**path;

  if ((path = gen_path(env)) == NULL)
    return (NULL);
  return (path);
}
