# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esukava <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 12:13:28 by esukava           #+#    #+#              #
#    Updated: 2020/10/21 12:56:39 by esukava          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_toupper.c \
	ft_tolower.c ft_isprint.c ft_isascii.c ft_isdigit.c \
	ft_isalpha.c ft_strstr.c ft_strnstr.c ft_bzero.c ft_memset.c \
	ft_isalnum.c ft_atoi1000.c \
	ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_putchar.c \
	ft_putendl.c ft_putnbr.c ft_putstr.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strclr.c ft_strequ.c \
	ft_itoa.c ft_strsplit.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_len.c ft_countwords.c \
	ft_strctrim.c ft_abs.c get_next_line.c ft_strndup.c

OUT	= $(SRCS:.c=.o)

INCLUDES = libft.h

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OUT)

clean :
	rm -f $(OUT)


fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
