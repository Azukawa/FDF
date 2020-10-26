# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esukava <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 17:29:30 by esukava           #+#    #+#              #
#    Updated: 2020/10/21 17:41:54 by esukava          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = _libft/libft.a
NAME = fdf
SRCS = srcs/main.c \
		srcs/read_file.c \
		srcs/init_grid.c \
		srcs/key_callback.c \
		srcs/draw_sec.c \
		srcs/draw_isom.c \
		srcs/draw_line.c \

OBJS = $(SRCS:.c=.o)
DEBUG = $(NAME).dSYM

.PHONY: all clean fclean re

all: $(NAME)

clean:
ifneq (,$(wildcard $(NAME).dSYM))
	@rm -r $(DEBUG)
	@echo "Deleted $(NAME).dSYM in $(NAME)"
endif
	@make -C _libft clean
	@rm -f $(OBJS)
	@echo "Deleted all .o files!"

fclean:
	@make -C _libft fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)
	rm -rf
	@echo "Deleted all .o files!"
ifneq (,$(wildcard .DS_Store))
	@rm -r .DS_Store
	@echo "Deleted .DS_Store in $(NAME)"
endif
ifneq (,$(wildcard $(NAME).dSYM))
	@rm -r $(DEBUG)
	@echo "Deleted $(NAME).dSYM in $(NAME)"
endif

re: fclean all

l:
	@make -C _libft
d:
	@gcc -g -Wall -Wextra -Werror $(SRCS) $(LIBFT)-lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
	@echo "Lldb debug folder"
	@echo "Compilation of $(NAME) successful!"

$(NAME): $(OBJS)
	@make -C _libft
	@gcc -Wall -Wextra -Werror $^ $(LIBFT) -lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
	@echo "Compilation of $(NAME) successful!"

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ $<
