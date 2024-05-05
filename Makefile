# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:03:23 by rnovotny          #+#    #+#              #
#    Updated: 2024/05/05 13:52:31 by rnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

SRC = src/so_long.c src/check.c src/check_input.c src/check_path.c \
	src/create_map.c src/door.c src/fetch.c src/move.c src/cleanup.c \

UTILS = utils/get_next_line.c utils/get_next_line_utils.c \
	utils/ft_bzero.c utils/ft_calloc.c utils/ft_itoa.c utils/ft_strdup.c

OBJS = so_long.o check.o check_input.o check_path.o \
	create_map.o door.o fetch.o move.o cleanup.o \
	get_next_line.o get_next_line_utils.o \
	ft_bzero.o ft_calloc.o ft_itoa.o ft_strdup.o

MLX_LIB = mlx/

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	
$(OBJS): $(SRC) $(UTILS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) -c $(CFLAGS) $(SRC) $(UTILS)

clean:
	@if [ -d "mlx" ]; then \
	make clean -C mlx/; \
	fi
	rm -rf $(OBJS)

fclean: clean
	rm -rf mlx
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re