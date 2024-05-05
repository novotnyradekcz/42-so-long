/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:48:10 by rnovotny          #+#    #+#             */
/*   Updated: 2024/05/05 12:15:15 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *game, int i, int j)
{
	game->player_position = UP;
	if (game->map[j + 1][i] == 'C')
		game->score += 1;
	else if (game->map[j + 1][i] == 'E' && game->collectibles == game->score)
		on_destroy(game);
	else if (game->map[j + 1][i] == 'E')
	{
		door_locked_up_down(game, j + 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j + 1][i] = 'P';
	put_player(game, i, j + 1);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}

void	move_up(t_game *game, int i, int j)
{
	game->player_position = DOWN;
	if (game->map[j - 1][i] == 'C')
		game->score += 1;
	else if (game->map[j - 1][i] == 'E' && game->collectibles == game->score)
		on_destroy(game);
	else if (game->map[j - 1][i] == 'E')
	{
		door_locked_up_down(game, j - 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j - 1][i] = 'P';
	put_player(game, i, j - 1);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}

void	move_left(t_game *game, int i, int j)
{
	game->player_position = LEFT;
	if (game->map[j][i - 1] == 'C')
		game->score += 1;
	else if (game->map[j][i - 1] == 'E' && game->collectibles == game->score)
		on_destroy(game);
	else if (game->map[j][i - 1] == 'E')
	{
		door_locked_right_left(game, j, i - 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i - 1] = 'P';
	put_player(game, i - 1, j);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}

void	move_right(t_game *game, int i, int j)
{
	game->player_position = RIGHT;
	if (game->map[j][i + 1] == 'C')
		game->score += 1;
	else if (game->map[j][i + 1] == 'E' && game->collectibles == game->score)
		on_destroy(game);
	else if (game->map[j][i + 1] == 'E')
	{
		door_locked_right_left(game, j, i + 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i + 1] = 'P';
	put_player(game, i + 1, j);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}
