/*
** levenshtein.h for  in /home/empoci_k/PSU_2014_42sh/Levenshtein/include
**
** Made by Kévin Empociello
** Login   <empoci_k@epitech.net>
**
** Started on  Mon May 18 16:35:54 2015 Kévin Empociello
** Last update Sun May 31 21:25:34 2015 Jean BARRIERE
*/

#ifndef LEVENSHTEIN_H_
# define LEVENSHTEIN_H_

/*
** INCLUDES
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <math.h>

/*
** KEYBOARD STRUCTURE
*/
typedef struct	s_keyboard
{
  char		*keyboard[4];
  int		xa;
  int		xb;
  int		ya;
  int		yb;
  int		x;
  int		y;
}		t_keyboard;

/*
** PROTOTYPES
*/
char		**try_dir(char *direct, char **path);
char		**gen_path(char **env);
char		**gen_data(char **env);
char		**cut_command(char *);
char		*levenshtein(char *str, char **env);
char		*get_next_line(const int fd);
char		*concatenate(char *, char *, char);
char		*cpy(char *str);
char		*change_command(char *, char *);
char		*po_s(char *str, int pos);
char		*tab_string(char **tabl);
char		*keyboard_precision(char **dic, char *command, int best);
char		*strdup(const char *s);
double		keyboard(char a, char b);
int		give_distance(char *str1, char *str2);
int		give_min(int a, int b, int c);
int		where_is_space(char *str);
int		is_separator(char c);
int		is_separator_ext(char c);
int		keyboard_distance(char *str1, char *str2);
int		str_len(char *str);
int		**fill_matrix(int **matrix);
int		**new_matrix(int, int, int **);
int		command_is_good(char *command, char **env);
int		check_command(char *str, char **env);
void		error(char *);
void		my_putchar(char);
void		display_matrix(int **matrix);
void		free_array(int **matrix);
void		free_array_char(char **matrix);
double		my_sqrt(double nb, int dec);
void		print_tab(char **);

#endif /* !LEVENSHTEIN_H_ */
