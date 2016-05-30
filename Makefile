##
## Makefile for  in /home/saurs_f/rendu/PSU_2014_minishell1
##
## Made by Florian Saurs
## Login   <saurs_f@epitech.net>
##
## Started on  Wed Jan  7 23:59:37 2015 Florian Saurs
## Last update Sun May 31 21:32:38 2015 Jean BARRIERE
##

SRCS		= access.c			\
		  alias.c			\
		  alias_next.c			\
		  auto_completion.c		\
		  auto_completion_check.c	\
		  auto_completion_check_multi.c	\
		  auto_completion_comp.c	\
		  auto_completion_dynamic.c	\
		  auto_completion_get.c		\
		  check_builts.c		\
		  clear_screen.c		\
		  command.c			\
		  command_exec.c		\
		  concatenate.c			\
		  create_42shrc.c		\
		  ctrls.c			\
		  ctrl_z.c			\
		  distance.c			\
		  echo.c			\
		  echo_end.c			\
		  echo_next.c			\
		  edit.c			\
		  edit_functs.c			\
		  edit_loop.c			\
		  epur.c			\
		  epur_str.c			\
		  errors_edit.c			\
		  exec_all.c			\
		  exit.c			\
		  final_free.c			\
		  find_funct.c			\
		  free_array.c			\
		  free_tab.c			\
		  funct_ctrl_z.c		\
		  generate.c			\
		  get_next_line.c		\
		  globbing.c			\
		  history.c			\
		  init_my_list.c		\
		  keyboard.c			\
		  levenshtein.c			\
		  list_edit.c			\
		  list_edit_special.c		\
		  list_hist.c			\
		  main.c			\
		  manage_ctrls.c		\
		  manage_specials.c		\
		  match.c			\
		  matrix.c			\
		  minishell.c			\
		  my_action_in_list.c		\
		  my_alias.c			\
		  my_atoi.c			\
		  my_dup.c			\
		  my_env.c			\
		  my_execute_redirect.c		\
		  my_execution.c		\
		  my_fct_built.c		\
		  my_other_action.c		\
		  my_param_term.c		\
		  my_pow.c			\
		  my_putchar.c			\
		  my_putstr.c			\
		  my_realloc.c			\
		  my_redirect.c			\
		  my_show_list.c		\
		  my_strcpy.c			\
		  my_strdup.c			\
		  my_strlen.c			\
		  my_third_action.c		\
		  print.c			\
		  print_env.c			\
		  print_list.c			\
		  prompt.c			\
		  put_42shrc.c			\
		  redirection.c			\
		  redir_double_left.c		\
		  select.c			\
		  separate_strings.c		\
		  setenv.c			\
		  show_list.c			\
		  signals.c			\
		  specials.c			\
		  statics.c			\
		  statics_son.c			\
		  str_to_wordtab.c		\
		  syntax.c			\
		  syntaxes.c			\
		  take_cmd.c			\
		  too_much.c			\
		  try_change.c			\
		  unsetenv.c			\
		  utils.c			\
		  utils_extends.c		\
		  utils_fct.c

NAME	= 42sh

CC	= gcc

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I./include/

LDFLAGS	= -lncurses

RM	= rm -f

RMDIR	= rm -rf

SDIR	= src

ODIR	= obj

OBJ	= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

$(ODIR)/%.o: $(SDIR)/%.c
	@if [ ! -d $(ODIR) ] ; then mkdir $(ODIR) ; fi
	$(CC) $(CFLAGS) $(INCDIR) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@if [ -d $(ODIR) ] ; then $(RMDIR) $(ODIR) ; fi

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
