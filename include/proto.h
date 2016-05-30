/*
** proto.h for  in /home/barrie_j/Documents/Sem_2/PSU_2014_42sh/RedBlackTree
**
** Made by Jean BARRIERE
** Login   <barrie_j@epitech.net>
**
** Started on  Thu Apr 23 16:45:23 2015 Jean BARRIERE
** Last update Sun May 31 22:16:18 2015 Jean BARRIERE
*/

#ifndef PROTO_H_
# define PROTO_H_

/*
** write.c
*/
int	my_strlen(char *str);
int	my_tablen(char **tabl);
int	compare_occurs(char c);

/*
** get_next_line.c
*/
char	*get_next_line(const int fd);

/*
** print.c
*/
int	put_msg_int(int out, char *msg, int ret);
void	*put_msg_ptr(int out, char *msg, void *ret);

/*
** my_strcmp.c
*/
int	my_strcmp(char *sa, char *sb);
int	my_strncmp(char *sa, char *sb, int max);
int	my_s_strncmp(char *s1, char *s2, int nb);

/*
** epur_str.c
*/
char	*epur_str(char *str, int flag);

/*
** parser_dtab.c
*/
char	**parse_global(char *str);

/*
** parser_ttab.c
*/
char	***parse_accuracy(char **parser);

/*
** exec_shl.c
*/
int	do_dup(int fd, int pipefd[2], int first);
int	check_builts(char *cmd, char **arg, char **env);
int	save_pid(int pid, int act);

/*
** free_rbt.c
*/
void	free_tab(char **tabl);

/*
** execute.c
*/
int	check_attribute(char *str);

/*
** access.c
*/
int	get_access(char **value, char  **env);

/*
** str_to_wordtab.c
*/
char	**str_to_wordtab(char *str, char delim);
char	*my_copy_line(char *str, int *start, char delim);
int	my_words(char *str, char delim);

/*
** check_builts.c
*/
int	check_builts(char *cmd, char **arg, char **env);
int	*update_jobs(int *tmp, int choice);
int	*action(int *jobs, int i, int status);
int	check_arg(char **arg, int opt);

/*
** echo.c
*/
int	my_echo(char **tabl, int past, int back);
char	**save_my_env(char **env);
int	check_more_opt(char **tabl, int i, int *special, int *back);

/*
** echo_next.c
*/
void	my_putstr(char *str);
int	cmpt_chaine(char *str, int i, int turn);
int	take_cmpt(char *str, int i, int turn, int compteur_base);
int	my_getnbr_base(char *str, int i, char *base, int turn);
void	my_putchar(char c);

/*
** chdir.c
*/
int	change_directory(char *my_path, char **env);

/*
** my_env.c
*/
char	*take_pwd(char **env);
char	*take_it(char **env, char *my_path, char *pwd);

/*
** my_fct_build.c
*/
char	**my_str_to_wordtab(char *s);
char	*my_strcat(char *dest, char *src);

/*
** ctrl_z.c
*/
void	ctrl_z();
int	*update_jobs(int *tmp, int choice);
int	*action(int *jobs, int i, int status);
int	my_jobs(int act, int nb);
int	kill(int pid, int flag);

/*
** alias.c
*/
char	*check_alias(char *cmd, char **env);
char	*my_concat(char *src, char *dest);

/*
** 42shrc.c
*/
void	create_42shrc(char **env);
char	*my_add(char *str, char *tabl);
int	is_alias(char *str);
char	**my_affect_line(char *s, int i, char **arg);
char	**my_str_wordtab(char *s);
char	*my_strcat(char *src, char *dest);

/*
** 42shrc.c
*/
void	put_alias(int fd);
int	is_alias(char *str);
int	is_export(char *str);

/*
** funct_ctrl_z.c
*/
int	*init_job();
void	ctrl_z();
void	close_fg(int *jobs, int i);

/*
** alias_next.c
*/
char	*my_take_place(char *src, char *dest, int end);
char	*find_it(char **tabl, char *cmd, int i);
char	**wordtab_pars(char *str, char **tabl, int i, int j);
char	*take_my_export_second(char *str);
char	*take_my_export_first(char *str);

#endif /* !PROTO_H_ */
