/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:11:44 by rnovotny          #+#    #+#             */
/*   Updated: 2024/05/05 12:35:12 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *game)
{
	free_map(game);
	free_textures(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	update_player_position(t_game *game, int key)
{
	int		i;
	int		j;
	char	*moves;

	i = game->x;
	j = game->y;
	if (key == 'w' && game->map[j - 1][i] != '1')
		move_up(game, i, j);
	else if (key == 's' && game->map[j + 1][i] != '1')
		move_down(game, i, j);
	else if (key == 'a' && game->map[j][i - 1] != '1')
		move_left(game, i, j);
	else if (key == 'd' && game->map[j][i + 1] != '1')
		move_right(game, i, j);
	moves = ft_itoa(game->moves);
	write(1, "                \r", 17);
	write(1, moves, ft_strlen(moves, '\0'));
	free(moves);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 'w' || keycode == 'a' \
	|| keycode == 's' || keycode == 'd')
		update_player_position(game, keycode);
	else if (keycode == 65307)
		on_destroy(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (save_map(argv[1], &game) == 1)
			exit(EXIT_FAILURE);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, (game.map_cols - 1) * 32, \
		(game.map_rows + 1) * 32, "so_long");
		open_images(&game);
		add_graphics(&game);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_hook(game.window, 17, 0, on_destroy, &game);
		mlx_loop(game.mlx);
	}
	else
		write(1, "Programm accepts no more or less than 1 argument\n", 49);
	exit(EXIT_SUCCESS);
}
