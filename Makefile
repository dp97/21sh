# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 09:37:16 by dpetrov           #+#    #+#              #
#    Updated: 2018/04/18 11:30:17 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 21sh

CC		= -gcc
CFLAGS	= #-Wall -Wextra -Werror

SRCS	= main.c err.c msc.c signal.c \
		  \
		  readline/tty.c readline/ft_readline.c readline/detect_ctrl.c \
		  readline/exec_ctrl.c readline/history.c readline/init.c \
		  readline/arrows.c readline/ft_log.c readline/s_chain.c \
		  readline/shift_plus_arrows.c readline/msc_keypad.c \
		  readline/cut_copy_paste.c readline/clipboard.c \
		  readline/quotes.c readline/delete_keys.c readline/auto_completion.c \
		  \
		  token_recognition/tokening.c token_recognition/deltokens.c\
		  \
		  execute/execute.c execute/path.c execute/builtin.c \
		  execute/ft_execve.c execute/pipe.c execute/ioe.c \
		  \
		  parser/parser.c parser/scmdhelper.c parser/cmdhelper.c parser/purger.c \
		  parser/prepare_redirection.c \
		  \
		  builtins/cd.c builtins/ft_setenv.c

OBJS			= $(SRCS:.c=.o)

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/
INCDIR		= -I includes/ -I libft/includes

SRC 	= $(addprefix $(SRC_PATH), $(SRCS))
OBJ		= $(addprefix $(OBJ_PATH), $(OBJS))

LFLAGS	= -Llibft -lft -ltermcap
DEPS	= ./libft/libft.a

.PHONY: all lib clean fclean re

all: lib $(NAME)

lib:
	@make -C libft/

$(NAME): $(OBJ) $(DEPS)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "\033[32m21SH:\t\t:LINKED [ ✔ ]\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c includes/*.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/execute
	@mkdir -p $(OBJ_PATH)/readline
	@mkdir -p $(OBJ_PATH)/token_recognition
	@mkdir -p $(OBJ_PATH)/parser
	@mkdir -p $(OBJ_PATH)/builtins
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;33m21SH:\t\t:CLEANED\033[0m"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[0;33m21SH:\t\t:FUlL CLEANED\033[0m"

re: fclean all

dev:
	@echo "\033[32m\t--> dpetrov <--\033[0m"
