/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:10:09 by rnovotny          #+#    #+#             */
/*   Updated: 2024/05/05 12:34:35 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH 32
# define HEIGHT 32
# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3
# define SPACE "img/space.xpm"
# define COLLECTIBLE "img/collectible.xpm"
# define EXIT "img/exit.xpm"
# define WALL "img/wall.xpm"
# define PLAYER "img/player.xpm"

# include "../mlx/mlx.h"
# include "../utils/get_next_line.h"
# include "../utils/utils.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_textures
{
	void	*space;
	void	*collectible;
	void	*door;
	void	*wall;
	void	*player;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			score;
	int			collectibles;
	int			moves;
	int			width;
	int			height;
	int			x;
	int			y;
	int			map_rows;
	int			map_cols;
	int			exit_row;
	int			exit_col;
	int			flood_fill_collectibles;
	int			current_frame;
	int			player_position;
	char		**map;
	t_textures	textures;
}	t_game;

int		main(int argc, char **argv);

// additional functions
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
int		on_destroy(t_game *game);

// check map
int		check_playable(t_game *game);
int		check_filename(char *file);
int		check_map(char *map, t_game *game);
int		valid_path(t_game *game);
int		check_char(t_game *game, int *p, int *e, int i);
int		check_last_row_rectangle(t_game *game);
void	check_playable_row(t_game *game, int *c, int *p, int *e);

// graphics
int		save_map(char *map, t_game *game);
void	open_images(t_game *game);
void	add_graphics(t_game *game);
void	put_player(t_game *game, int width, int height);
void	open_score(t_game *game);
void	door_locked_up_down(t_game *game, int door_row, int door_col);
void	door_locked_right_left(t_game *game, int door_row, int door_col);

// player controls
void	move_up(t_game *game, int i, int j);
void	move_down(t_game *game, int i, int j);
void	move_right(t_game *game, int i, int j);
void	move_left(t_game *game, int i, int j);

// free memory
void	free_map(t_game *game);
void	free_textures(t_game *game);
void	free_visited(int **visited, t_game *game);

#endif