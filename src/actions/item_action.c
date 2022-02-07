/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:59:19 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 19:21:16 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	item_animation(t_item *item)
{
	if (item->going_up)
	{
		if (item->frame <= 0)
			item->going_up = 0;
		else
			item->frame -= .6;
	}
	else
	{
		if (item->frame > 7)
			item->going_up = 1;
		else
			item->frame += .6;
	}
}

static int	item_collision(int x, int y, t_game *game)
{
	if ((game->player.x + game->map.x) == x && \
		(game->player.y + game->map.y) == y)
		return (1);
	return (0);
}

static void	free_item(t_item *last_one, t_item *item, t_game *game)
{
	if (!last_one)
		game->items = item->next;
	else
		last_one->next = item->next;
	free(item->sprite.img);
	free(item);
}

void	rdi(t_game *game, t_item *item, t_item *last_one, int x)
{
	int	y;

	while (item)
	{
		if (is_on_map(item->x, item->y, game))
		{
			x = (item->x - game->map.x) * BLOCK_SIZE;
			y = (item->y - game->map.y) * BLOCK_SIZE;
			if (item_collision(item->x, item->y, game))
			{
				free_item(last_one, item, game);
				if (!last_one)
					last_one = game->items;
				if (!last_one)
					break ;
				item = last_one->next;
				continue ;
			}	
			copy_img_to(&game->map.map, &item->sprite,
				to_array(x, y + item->frame, BLOCK_SIZE, BLOCK_SIZE));
			item_animation(item);
		}
		last_one = item;
		item = item->next;
	}
}

void	render_items(t_game *game)
{
	t_item	*item;
	t_item	*last_one;
	int		x;

	item = game->items;
	last_one = 0;
	rdi(game, item, last_one, x);
}
