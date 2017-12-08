# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/06 13:52:21 by dpetrov           #+#    #+#              #
#    Updated: 2017/12/08 11:57:21 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

################# LIBFT ################

LFT_SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlen.c \
		  ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
		  ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		  ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
		  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		  ft_memmove.c ft_putchar.c ft_putstr.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putendl.c \
		  ft_putendl_fd.c ft_strclr.c ft_strdel.c ft_memalloc.c ft_memdel.c \
		  ft_strnew.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		  ft_strsplit.c ft_memchr.c ft_memcmp.c ft_itoa.c ft_lstnew.c \
		  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		  ft_strndup.c ft_str_case.c ft_strapnd.c ft_putstrstr.c \
		  ft_foreach.c ft_stredit.c get_next_line.c

LFT_PATH	= srcs/
LFT_SRC 	= $(addprefix $(LFT_PATH), $(LFT_SRCS))
IN_LFT		= -I./includes

OBJ_PATH	= ./objs/

OBJS 		= $(LFT_SRCS:.c=.o)

ALL_OBJ		= $(addprefix $(OBJ_PATH), $(OBJS))

IN_ALL		= $(IN_LFT)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(ALL_OBJ)
	@ar rc $(NAME) $(ALL_OBJ)
	@ranlib $(NAME)
	@echo "\033[32m\t\t||||||||||||||||||\033[0m"
	@echo "\033[32m\t\t|||   DONE !   |||\033[0m"
	@echo "\033[32m\t\t||||||||||||||||||\033[0m"

$(OBJ_PATH)%.o: $(LFT_PATH)%.c ./includes/*.h
	@mkdir -p $(OBJ_PATH)
	$(CC) $(IN_ALL) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[35mLIB_FT:\t\t:CLEANED\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[32mLIB_FT:\t\t:FUlL CLEANED\033[0m"

re: fclean all
