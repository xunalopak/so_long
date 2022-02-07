/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:59:24 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 19:07:49 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_over(t_game *game)
{
	t_data			game_over;
	int				x;
	int				y;

	game_over.w = 544;
	game_over.h = 416;
	load_img(&game_over, "./imgs/over.xpm", game);
	x = (game->width * BLOCK_SIZE) - game_over.w;
	if (x < 0)
		x = 0;
	y = (game->height * BLOCK_SIZE) - game_over.h;
	if (y < 0)
		y = 0;
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game_over.img, x, y);
	free(game_over.img);
}

void	print_screen(t_game *game)
{
	t_data			img;
	int				x;
	int				y;

	img.w = 255;
	img.h = 255;
	load_img(&img, "./imgs/v.xpm", game);
	x = (game->width * BLOCK_SIZE) / 2 - img.w;
	if (x < 0)
		x = 0;
	y = ((game->height * BLOCK_SIZE) / 2) - img.h;
	if (y < 0)
		y = 0;
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		img.img, x, y);
	free(img.img);
}
