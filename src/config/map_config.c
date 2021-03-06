/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:58:02 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:58:04 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_active_map(t_game *game)
{
	int	w;
	int	h;
	int	x;
	int	y;

	w = game->width * BLOCK_SIZE;
	h = game->height * BLOCK_SIZE;
	if (!game->map.map.img)
	{
		create_img(&game->map.map, w, h, game);
		fix_cam(game);
	}
	x = game->map.x * BLOCK_SIZE;
	y = game->map.y * BLOCK_SIZE;
	copy_img_from(&game->map.map, &game->map.full_map, to_array(x, y, w, h));
}

static void	set_tile(char c, t_game *game, int x, int y)
{
	t_data			tile;
	char			*path;
	static size_t	i;
	int				size;

	size = BLOCK_SIZE;
	if (c == '1')
		path = "./imgs/wall3.xpm";
	if (c == 'E')
		path = "./imgs/exit_lock.xpm";
	if (c == 'C' || c == 'P' || c == '0')
	{
		if (i % 18 == 0)
			path = "./imgs/floor4.xpm";
		else if (i % 28 == 0)
			path = "./imgs/floor5.xpm";
		else
			path = "./imgs/floor3.xpm";
		i++;
	}
	load_img(&tile, path, game);
	copy_img_to(&game->map.full_map, &tile, to_array(x, y, size, size));
	free(tile.img);
}

static void	draw_block(t_game *game, int x, int y)
{
	t_data	sprite;
	char	block;
	int		real_x;
	int		real_y;

	block = game->map.layout[y][x];
	real_x = x * BLOCK_SIZE;
	real_y = y * BLOCK_SIZE;
	if (block == 'P')
	{
		game->player.x = x;
		game->player.y = y;
	}
	if (block == 'C')
		new_item(game, x, y);
	set_tile('0', game, real_x, real_y);
	set_tile(block, game, real_x, real_y);
}

void	map_config(t_game *game)
{
	int		x;
	int		x_holder;
	int		y;

	x = game->map.w;
	x_holder = x;
	y = game->map.h;
	game->map.x = 0;
	game->map.y = 0;
	game->map.map.img = 0;
	create_img(&game->map.full_map, x * BLOCK_SIZE, y * BLOCK_SIZE, game);
	while (y--)
	{
		while (x--)
			draw_block(game, x, y);
		x = x_holder;
	}
}
