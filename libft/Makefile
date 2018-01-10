# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/06 13:52:21 by dpetrov           #+#    #+#              #
#    Updated: 2017/12/08 16:43:25 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

################# LIBFT ################

SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlen.c \
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
		  ft_foreach.c ft_stredit.c get_next_line.c ft_lastchar.c \
			ft_strrev.c ft_strrevcmp.c ft_strrevncmp.c ft_straddch.c \
			ft_2dstrdel.c

OBJS        = $(SRCS:.c=.o)

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/

SRC 		= $(addprefix $(SRC_PATH), $(SRCS))
OBJ         = $(addprefix $(OBJ_PATH), $(OBJS))

INCDIR		= -I includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m||||||||||||||||||\033[0m"
	@echo "\033[32m|||   DONE !   |||\033[0m"
	@echo "\033[32m||||||||||||||||||\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./includes/*.h
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[35mLIB_FT:\t\t:CLEANED\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[32mLIB_FT:\t\t:FUlL CLEANED\033[0m"

re: fclean all
