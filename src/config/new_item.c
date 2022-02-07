/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:57:06 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:57:08 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	new_item(t_game *game, int x, int y)
{
	t_item	*begin;
	t_item	*new_item;

	new_item = (t_item *) ft_calloc(1, sizeof(t_item));
	new_item->x = x;
	new_item->y = y;
	new_item->sprite.w = BLOCK_SIZE;
	new_item->sprite.h = BLOCK_SIZE;
	load_img(&new_item->sprite, "./imgs/item.xpm", game);
	begin = game->items;
	while (begin && begin->next)
		begin = begin->next;
	if (begin)
		begin->next = new_item;
	else
		game->items = new_item;
}
