/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:58:19 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:58:21 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_config(t_game *game)
{
	game->vars.mlx = mlx_init();
	map_config(game);
	player_config(game);
	enemy_config(game);
	if (game->map.w > 14)
		game->width = 14;
	else
		game->width = game->map.w;
	if (game->map.h > 10)
		game->height = 10;
	else
		game->height = game->map.h;
	game->vars.win = mlx_new_window(game->vars.mlx, game->width * BLOCK_SIZE,
			game->height * BLOCK_SIZE, "Dungeon Zone");
}
