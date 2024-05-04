# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:03:23 by rnovotny          #+#    #+#              #
#    Updated: 2024/05/04 18:08:19 by rnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

SRC = src/so_long.c src/check.c src/check_input.c src/check_path.c \
	src/create_map.c src/door.c src/fetch.c src/move.c src/cleanup.c \

UTILS = utils/get_next_line.c utils/get_next_line_utils.c \
	utils/ft_bzero.c utils/ft_calloc.c utils/ft_itoa.c utils/ft_strdup.c

OBJS = $(SRC:.c=.o)

MLX_LIB = mlx/

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(UTILS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	@if [ -d "mlx" ]; then \
	make clean -C mlx/; \
	fi
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re