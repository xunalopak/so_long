/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:58:25 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:58:27 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	player_on_screen(int x, int y, t_game *game)
{
	int	x_max;
	int	x_hold;
	int	y_max;

	x_hold = x;
	x_max = x + game->width;
	y_max = y + game->height;
	while (y < y_max)
	{
		while (x < x_max)
		{
			if (game->map.layout[y][x] == 'P')
				return (1);
			x++;
		}
		x = x_hold;
		y++;
	}
	return (0);
}

int	fix_cam(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y + game->height <= game->map.h)
	{
		while (x + game->width <= game->map.w)
		{
			if (player_on_screen(x, y, game))
			{
				game->map.x = x;
				game->map.y = y;
				game->player.x -= x;
				game->player.y -= y;
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
