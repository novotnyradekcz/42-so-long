/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:13:16 by rnovotny          #+#    #+#             */
/*   Updated: 2024/05/05 12:14:38 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->window, \
	game->player.player_idle_right_1, 0 + width * 32, 0 + (height * 32));
	game->x = width;
	game->y = height;
}

static int	open_textures(t_game *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
	SPACE, &game->width, &game->height);
	if (game->textures.ground == NULL)
		return (1);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx, \
	COLLECTIBLE, &game->width, &game->height);
	if (game->textures.collectible == NULL)
		return (1);
	game->textures.door = mlx_xpm_file_to_image(game->mlx, \
	EXIT, &game->width, &game->height);
	if (game->textures.door == NULL)
		return (1);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	WALL, &game->width, &game->height);
	if (game->textures.wall == NULL)
		return (1);
	return (0);
}

void	open_images(t_game *game)
{
	game->height = HEIGHT;
	game->width = WIDTH;
	game->current_frame = 0;
	game->player.player_idle_right_1 = mlx_xpm_file_to_image(game->mlx, \
	PLAYER, &game->width, &game->height);
	if (open_textures(game) == 1)
		write(1, "Failed to open the image\n", 25);
}
