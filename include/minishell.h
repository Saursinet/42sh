/*
** minishell.h for minishell in /home/saursf/rendu/PSU_2014_minishell1/include
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Jan 13 14:50:19 2015 Florian Saurs
** Last update Sun May 31 22:17:29 2015 Jean BARRIERE
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

/*
** INCLUDES
*/
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "types.h"

/*
** UNUSED PARAMS
*/
# define UNUSED	__attribute__((unused))

/*
** SIZE TO READ
*/
# define BUFF_SIZE 4096

/*
** REDIRECT STRUCT
*/
typedef struct	s_redirect
{
  int		fd;
  int		pid;
  int		pipefd[2];
  int		c;
  int		status;
  char		**tabl;
  char		*str;
}		t_redirect;

/*
** PROTOTYPES
*/
char	*find_my_funct(char **env, char *my_src);
char	**my_str_to_wordtab(char *s);
int	print_env(char **env);
char	**past_my_env(char **env);
void	my_son(char *my_src, char *s, char **env);
void	free_my_env(char **env);
int	for_my_env(char **env, char *s, int i);
int	change_directory(char *my_path, char **env);
char	*take_it(char **env, char *my_path, char *pwd);
int	len(char *str);
char	**my_wordtab(char *s, char c);
int	check_buff(char *s);
int	check_pipe(char *s);
char	*check_exist(char **el_camino, char **tabl);
int	call_my_pipe(char *s, char **env, char **el_camino);
char	**my_env(char **tabl, int i);
char	**my_wordfortab(char *s);
void	rig_s(char **s, int i);
void	rig_d(char **s, int i);
void	left_simple(char **arg, int i);
void	double_left_red(char **arg, int i);
char	*take_pwd(char **env);
int	put_father(t_param *par, char **arg, char **el_camino, char **env);
char	**wordtab(char *s);
int	my_redir_double_left(char **args, int i, t_param *par);
char	**my_compline(char *s, int i, char **arg);
char	**save_my_env(char **env);
void	create_42shrc(char **env);
int	check_42shrc(int fd);
char	**parse_it(char *tabll);
char	*take_tab(char **arg);
char	*change_it(char *cmd, int fd);
char	*my_concat(char *src, char *dest);
char	*take_my_pwd(char *str, char **env);
char	*check_alias(char *cmd, char **env);
int	is_alias(char *str);
int	is_export(char *str);
int	my_strncmp(char *s1, char *s2, int nb);
int	my_strlen(char *str);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strcat(char *dest, char *src);
void	my_put_nbr(int nb);
int	my_echo(char **tabl, int past, int back);
int	my_unsetenv(char **env, char *name);
int	my_setenv(char **env, char *name, char *value);
int	place_env(char **env);
int	exec_that(char *arg, char **tabl, char **env);
void	init_history(char **cmd, t_hist **hist, char **term, int *stop);

#endif /* !MINISHELL_H_ */
