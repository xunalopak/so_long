/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:58:29 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:58:31 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	new_fireball(t_game *game, int x, int y)
{
	t_fireball	*begin;
	t_fireball	*new_item;

	new_item = (t_fireball *) ft_calloc(1, sizeof(t_fireball));
	new_item->x = x;
	new_item->y = y;
	new_item->sprite.w = 64;
	new_item->sprite.h = 64;
	load_img(&new_item->sprite, "./imgs/fireball/1.xpm", game);
	begin = game->fireballs;
	while (begin && begin->next)
		begin = begin->next;
	if (begin)
		begin->next = new_item;
	else
		game->fireballs = new_item;
}
