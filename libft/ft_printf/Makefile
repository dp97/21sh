# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 08:57:51 by dpetrov           #+#    #+#              #
#    Updated: 2017/01/03 14:55:22 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

IN		= -I./includes/

OBJ_PATH = ../objs/
SRC_PATH = ./src/

SRCS	= ft_printf.c functions.c convert.c util.c print.c color.c float.c \
		  format_specifiers.c handle_1.c handle_2.c conversion.c convert_p.c \
		  pre_conversion.c
SRC     = $(addprefix $(SRC_PATH),$(SRCS))

OBJS    = $(SRCS:.c=.o)
OBJ		= $(addprefix $(OBJ_PATH),$(OBJS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mFT_PRINTF:\t\t:BUILDED\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(IN) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[32mFT_PRINTF:\t\t:CLEANED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mFT_PRINTF:\t\t:FULL CLEANED\033[0m"

re: fclean all
