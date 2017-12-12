# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 09:37:16 by dpetrov           #+#    #+#              #
#    Updated: 2017/12/12 13:24:51 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 21sh

CC		= -gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c ft_loop.c execute.c launch.c \
		  ft_get_args.c check_dollar_1.c check_dollar_2.c err.c sig.c \
		  parser/quotes.c parser/wildcard.c \
		  parser/home_symbol.c parser/parser.c \
		  builtins/env.c builtins/echo.c builtins/cd.c builtins/exit.c \
		  builtins/setenv.c builtins/history.c \
		  free_mem/free_2d.c free_mem/free_1d.c free_mem/free_the_chain.c \
		  \
		  readline/tty.c readline/ft_readline.c readline/detect_ctrl.c \
		  readline/exec_ctrl.c readline/history.c readline/init.c \
		  readline/arrows.c readline/ft_log.c readline/input_stream.c \
		  readline/shift_arrows.c readline/copy_paste.c readline/msc_keypad.c

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
	@mkdir -p $(OBJ_PATH)/builtins
	@mkdir -p $(OBJ_PATH)/parser
	@mkdir -p $(OBJ_PATH)/free_mem
	@mkdir -p $(OBJ_PATH)/readline
	$(CC) $(INCDIR) -c $< -o $@

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
