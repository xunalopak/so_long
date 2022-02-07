/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:57:02 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:57:04 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_config(t_game *game)
{
	t_data		full_sprite;
	t_player	*player;
	int			i;

	i = 0;
	player = &game->player;
	player->steps = 0;
	full_sprite.w = 144;
	full_sprite.h = 256;
	player->w = 48;
	player->h = 64;
	player->frame = 2;
	load_img(&full_sprite, "./imgs/male.xpm", game);
	while (i < 4)
	{
		create_img(&player->sprites[i], player->w, player->h, game);
		copy_img_from(&player->sprites[i], &full_sprite,
			to_array(0, player->h * i, player->w, player->h));
		i++;
	}
}
