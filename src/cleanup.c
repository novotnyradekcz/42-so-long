/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:46:14 by rnovotny          #+#    #+#             */
/*   Updated: 2024/05/05 12:34:20 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visited(int **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free (game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.collectible);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.space);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_image(game->mlx, game->textures.player);
}
