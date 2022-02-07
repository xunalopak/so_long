/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:58:43 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:58:43 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_mov(t_game *game, int x, int y)
{
	y += game->player.y + game->map.y;
	x += game->player.x + game->map.x;
	if (game->map.layout[y][x] != '1')
		return (1);
	return (0);
}
