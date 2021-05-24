# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 19:27:35 by sbroderi          #+#    #+#              #
#    Updated: 2020/11/20 04:25:09 by sbroderi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_DIR = ./srcs/

INCLUDES = -I./includes/

LIST = ft_cd.c \
	   ft_data_parser.c \
	   ft_data_parser_helper.c \
	   ft_exe.c \
	   ft_export.c \
	   ft_unset.c \
	   ft_exe_helper.c \
	   get_next_line_utils.c \
	   ft_exit.c \
	   ft_check_arg.c \
	   ft_dollar.c \
	   get_next_line.c \
	   ft_handle_redir.c \
	   ft_echo.c \
	   ft_find_word.c \
	   ft_handle_rev_redir.c \
	   ft_split.c \
	   ft_strtrim.c \
	   ft_lists.c \
	   ft_print_env.c \
	   ft_find_double_quote.c \
	   main.c \
	   ft_hidden.c \
	   ft_command_selector.c \
	   ft_itoa.c \
	   ft_handle_pipe.c \
	   ft_check_redir_arg.c \
	   ft_selector.c \
	   ft_atoi.c \
	   ft_substr.c \
	   ft_start_error.c \
	   ft_find_quote.c \
	   ft_check_double_pipe_semicolon.c \
	   ft_strjoin_char.c \
	   ft_copy_env.c \
	   ft_strncmp.c \
	   ft_shield.c \
	   ft_find_env_arg.c \
	   ft_strcmp.c \
	   ft_sigint.c \
	   ft_calloc.c \
	   ft_print_export_err.c \
	   ft_memcpy.c \
	   ft_handle_semicolon.c \
	   move_helper.c \
	   ft_putstr_fd.c \
	   ft_fill_content_tmp.c \
	   ft_pwd.c \
	   ft_skip_spases.c \
	   ft_swap_str.c \
	   ft_isalpha.c \
	   ft_strlen.c \
	   ft_putchar_fd.c \
	   ft_isdigit.c
SRC = $(addprefix $(SRC_DIR), $(LIST))
OBJ = $(patsubst %.c,%.o,$(SRC))

FLAGS = -Wall -Wextra -Werror -O2

.PHONY: all, clean, fclean, re, norm

all: $(NAME)

$(NAME): $(OBJ)

	gcc $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c ./includes/minishell.h ./includes/structures.h
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

norm:	
	@norminette $(SRC)
	@norminette ./includes/minishell.h ./includes/structures.h
