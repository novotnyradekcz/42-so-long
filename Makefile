# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:03:23 by rnovotny          #+#    #+#              #
#    Updated: 2024/05/04 16:04:54 by rnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

SRC = src/*.c utils/*.c

GETNEXTLINE = get_next_line/*.c

OBJS = $(SRC:.c=.o)

MLX_LIB = mlx/

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(GETNEXTLINE) $(MLX_FLAGS) -o $(NAME)

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