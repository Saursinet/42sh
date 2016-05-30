/*
** edit.h for edit in /home/wilmot_g/.ssh/PSU_2014_42sh/Dieu/NewEditionFull
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu Apr 30 14:33:53 2015 guillaume wilmot
** Last update Sun May 31 22:09:08 2015 Jean BARRIERE
*/

#ifndef EDIT_H_
# define EDIT_H_

/*
** INCLUDES
*/
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <glob.h>
# include <signal.h>
# include <stdlib.h>
# include <termios.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include <term.h>
# include <ncurses/curses.h>
# include "levenshtein.h"
# include "types.h"

/*
** DEFINES
*/
# define UP 4283163
# define DOWN 4348699
# define LEFT 4479771
# define RIGHT 4414235
# define ENTER 10
# define UNUSED __attribute__((unused))

/*
** STRUCTURES
*/
typedef struct  s_list
{
  char          *param;
  int           cmpt;
  int           pos;
  int           select;
  struct s_list *next;
  struct s_list *prev;
}               t_list;

typedef struct  s_tools
{
  char          *termtype;
  int           success;
  char          *cl_string;
  char          *color_string;
  char          *color_end_string;
  char          *underline_string;
  char          *underline_end_string;
  char          *term_buffer;
  char          *clear_line;
  char          *pos_string;
  char          *set_cursor;
  char          *return_line;
  char          *invisible_cursor;
  char          *visible_cursor;
  char          *gras_text;
  char		*command;
  char		*folder;
  int           i;
}               t_tools;

typedef struct  s_param
{
  int		backs[2];
  int           my_length;
  int           length;
  int           cmpt;
  int		no;
  int		no_bis;
  int		advance;
  int           my_cmpt;
  int           buff;
  char          *str;
  int		i;
  int		stock;
  int		stock_bak;
  int		action;
}		t_param;

typedef struct	s_edit t_edit;
struct	s_edit
{
  t_edit        *next;
  t_edit        *prev;
  int           actual;
  char          *c;
};

typedef struct s_hist t_hist;
struct          s_hist
{
  t_hist        *next;
  t_hist        *prev;
  t_edit        *edit;
};

typedef struct s_main t_main;
struct          s_main
{
  t_hist	*history;
  char		*cmd;
  char		*term;
  char		**paths;
  char		**my_env;
  int		stop;
};

typedef struct s_cmd t_cmd;
struct          s_cmd
{
  int           ret;
  int           i;
  int           buf_nbr;
  char          *buf;
  char          *pos;
  char          *cmd;
  char		*clip;
};

typedef struct	s_var
{
  int		i;
  int		c;
  int		ret;
}		t_var;

struct winsize	init_my_ioctl();

/*
** PROTOTYPES
*/
t_var		parsing_part_two(const char *, t_var);
t_var		parsing_part_three(const char *, t_var, char *);
t_var		initialize_my_struct(t_var);
t_tools		my_keep_tool(t_tools);
t_list		*my_keep_list(t_list *);
t_list		*init_my_list(char **, t_tools);
t_edit		*my_remove_s_edit_link(t_edit *);
t_edit		*my_edit_dup(t_edit *);
t_edit		*root_hist();
t_hist		*get_hist(t_hist *);
char		**get_multi_match(char *, char *, int);
char		**get_special_multi_match(char *, char *);
char		**get_multi_match_multi(char **, char *, int, int);
char		**get_special_multi_match_multi(char **, char *, int, int);
char		**my_realloc_double_tab(char **, int);
char		**del_duplicates(char **);
char		**str_to_word_tab(char *);
char		*concat_tab(char **);
char		*my_placement(t_tools, t_list *);
char		*glob_this(char *);
char		*my_epur(char *);
char		*get_folder(char *);
char		*my_del_str(char *, t_tools);
char		*my_str_cmp(char *, char *);
char		*update_too_much(char **);
char		*get_next_line(int);
char		*concatenate(char *, char *, char);
char		*set_too_much(char **, t_edit *, int *, char *);
char		*reset_too_much(char **);
char		*get_position(char *);
char		*get_cmd(t_hist **, char *, int *, char **);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
char		*take_cmd(t_edit *, int, int *);
char		*take_cmd_until(t_edit *);
char		*take_cmd_comp(t_edit *);
char		*get_signal();
char		*get_term(char *);
char		*end_edit(char **, t_cmd *, t_edit *, t_hist **);
char		*init_too_much(char **, int *);
char		*ctrl_l(char *);
char		*my_clear(char *);
char		*update_prompt(char **);
char		*end_acquisition(t_hist **, t_edit *, char *, t_cmd *);
char		*itos(int);
char		*get_user(char **, char *);
char		*get_folder_for_comp(char *);
char		*get_command_for_comp(char *);
char		*set_position(char *, char *);
char		*check_other_match(char *, char *);
char		*check_single_match(char *, char *);
char		*check_special_single_match(char *, char *);
char		*check_other_match_multi(char **, char *);
char		*check_single_match_multi(char **, char *, int, int);
char		*check_special_single_match_multi(char **, char *, int, int);
char		*my_strupcase(char *);
char		*my_strcpy(char *, char *);
char		*my_strncpy(char *, char *, int);
char		*my_revstr(char *);
char		*my_strstr(char *, char *);
char		*my_strlowcase(char *);
char		*my_strcapitalize(char *);
char		*my_strcat(char *, char *);
char		*my_strncat(char *, char *, int);
char		*selectt(char **, char *, char *, char *);
char		*get_color_style(char *);
char		my_min(char);
int		*get_ctrls();
int		*get_specials();
int		manage_too_much(t_edit *);
int		check_for_char(char *, char);
int		set_canon(int);
int		my_pow(int, int);
int		my_put_in_s_hist(t_hist **, t_edit *);
int		free_hist(t_hist *);
int		biggest_in_tab(char **);
int		my_strlen(char *);
int		my_show_list(t_list *, t_tools, char *);
int		my_put(int);
int		my_struct(t_tools *, char *, char *, char *);
int		find_print(t_list *, struct winsize);
int		keep_fd(int);
int		my_find(t_list **, t_tools, int);
int		my_length(t_list *);
int		my_isneg(int);
int		my_swap(int *, int *);
int		my_strlen(char *);
int		my_getnbr(char *);
int		my_power_rec(int, int);
int		my_square_root(int);
int		my_is_prime(int);
int		my_find_prime_sup(int);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_str_isalpha(char *);
int		my_str_isnum(char *);
int		my_str_islower(char *);
int		my_str_isupper(char *);
int		my_str_isprintable(char *);
int		my_showstr(char *);
int		my_showmem(char *, int);
int		my_strlcat(char *, char *, int);
int		my_putnbr_base(int, char *);
int		conditions_annex(const char *, va_list, int);
int		exec(char *, char **);
int		my_putstr_print(char *);
int		is_too_much(int);
int		my_putnbr_inoctal_for_o(unsigned int, char *);
int		my_put_unsigned_nbr(unsigned int);
int		my_putnbr_inhexa(unsigned int, char *);
int		my_printf(const char *, ...);
int		dec(va_list);
int		string(va_list);
int		octal(va_list);
int		unsigned_dec(va_list);
int		unsigned_hex(va_list);
int		unsigned_hex_maj(va_list);
int		character(va_list);
int		pointer(va_list);
int		string_printable(va_list);
int		bin(va_list);
int		my_putnbr_inhexa(unsigned int, char *);
int		my_putnbr_with_base(unsigned long int, char *);
int		my_putstr_printable(unsigned char *);
int		my_putnbr_bin(int, char *);
int		my_putnbr(int);
int		my_show(t_list **, t_tools, struct winsize, t_param);
int		my_putnbr(int);
int		set_visibility_cursor(char *, int);
int		my_putstr_special(char *, int, char *);
int		move_actual(t_edit **, int);
int		my_show_s_edit(t_edit *, char *);
int		my_put_in_s_edit(t_edit **, char *);
int		my_put_in_s_edit_next(t_edit **, char *);
int		my_putchar_int(int);
int		delete_actual(t_edit *, int);
int		init_edit(t_edit **, t_cmd *, char *, char *);
int		hidden_match(char *, char *);
int		beggin_match(char *, char *);
int		match(char *, char *);
int		my_atoi(char *);
int		my_int_errors(char *, int);
int		my_edit_free(t_edit *);
int		ctrl_k(t_edit **, t_cmd *);
int		ctrl_u(t_edit **, t_cmd *);
int		ctrl_t(t_edit **, t_cmd *);
int		ctrl_y(t_edit **, t_cmd *);
int		ctrl_e(t_edit **, t_cmd *);
int		ctrl_a(t_edit **, t_cmd *);
int		ctrl_right(t_edit **, t_hist **);
int		ctrl_left(t_edit **, t_hist **);
int		hist_top(t_edit **, t_hist **);
int		put_spec_car(char *, int, const char[8], const char[8]);
int		get_return_value(int, int, int, int);
int		check_exit(char **, int, int);
int		check_env(char *, int);
int		hist_bottom(t_edit **, t_hist **);
int		show_multi_match(char **, char *, t_edit **, char *);
int		spe_suppr(t_edit **, t_hist **);
int		prompt(char **);
int		check_syntax(char *, char **);
int		update_fils(int, int);
int		check_syntaxes(char **, char **);
int		check_return_value(char **, char **, char **);
int		stop_function(char, char *);
int		exec_that(char *, char **, char **);
int		check_struct(t_edit **, char *, char *);
int		check_struct_bin(t_edit **, char *, char **, char *);
int		stop_this(char **, int);
int		auto_comp(t_edit **, t_cmd *, char **, int);
int		start_auto(char **, char *, char *, t_edit **);
int		complete(t_edit **, char *);
int		stat_dynamic(char **, t_edit **, char *);
void		separate_strings(t_edit **);
void		concat_edit(t_edit **, t_edit *);
void		init_history(char **, t_hist **, char **, int *);
void		manage_ctrls_and_specials(t_edit **, t_cmd *, t_hist **);
void		my_suppr_s_edit_link(t_edit *);
void		manage_specials(t_edit **, t_cmd *, t_hist **);
void		my_final_free(char **, char *, char **, t_hist *);
void		my_put_nbr(int);
void		move_cursor(t_edit **, int, t_hist **);
void		my_putstr(char *);
void		my_putchar(char);
void		put_too_much(t_edit **, char **);
void		choose_edit(t_edit **, int *, t_cmd *, t_hist **);
void		prompt_sig();
void		my_free(void *);
void		print_one_word(struct winsize, t_list **, t_tools);
void		my_reverse_select(t_list **, t_tools);
void		change_mod();
void		show_list_end(t_tools, t_list *, struct termios);
void		my_put_str(char *);
void		my_putstr(char *);
void		my_restore(t_tools, struct termios);
void		my_conditions(t_tools, t_list **, int);
void		my_list_in_order(t_list **, t_tools, int);
void		my_selection(t_list **, t_tools);
void		my_empty_selection(t_list **, t_tools);
void		my_resize();
void		my_end();
void		my_printer(t_list **, t_tools);
void		my_toolbar(t_list **, t_tools);
void		my_next(t_tools, t_list **, int);
void		free_my_list(t_list *, t_tools);
void		my_putstr(char *);
void		global_edit(t_cmd *, t_edit **, int *, t_hist **);
void		initialize_my_pointer_function(int (**)(va_list), char *);
void		my_other_placement(t_tools, t_list **, int);
void		wait_to_react(char *);
void		reback_my_dup(int[2]);
void		replace_history_aliases(char **, t_hist **);
void		globbing(char **);
void		globbing_and_such(char **, t_hist **, char **, char **);
void		free_double_tab(char **);
void		*reset_pos(char *, char **, t_edit *, int);
void		*my_errors(char *, void *);

#endif /* !EDIT_H_ */
