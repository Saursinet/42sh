/*
** utils_extends.c for  in /home/empoci_k/PSU_2014_42sh/Levenshtein
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Sun May 24 01:19:32 2015 Kévin Empociello
** Last update Sun May 24 22:45:36 2015 Kévin Empociello
*/

#include "edit.h"

int	where_is_space(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str && str[i] != '\0' && str[i] != '\0')
    i++;
  return (i);
}

char	*po_s(char *str, int pos)
{
  char	*new;
  int	i;

  i = 0;
  if ((new = malloc((strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (i < pos && str && str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

char	*tab_string(char **tabl)
{
  int   i;
  char  *tmp;
  char  *tmp2;

  i = 0;
  tmp = NULL;
  tmp2 = NULL;
  while (tabl && tabl[i] != NULL)
    {
      tmp = concatenate(tmp2, tabl[i], ' ');
      free(tmp2);
      tmp2 = tmp;
      i++;
    }
  free_array_char(tabl);
  return (tmp);
}

int	is_separator_ext(char c)
{
  if (c == '|' || c == ';' ||
      c == '&' || c == '`')
    return (0);
  else
    return (-1);
}

int	is_separator(char c)
{
  if (c == '|' || c == ';' ||
      c == '>' || c == '<' ||
      c == '&' || c == '`')
    return (0);
  else
    return (-1);
}
