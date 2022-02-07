/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:59:33 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 19:06:41 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_fireball(t_fireball *last_one, t_fireball *ball, t_game *game)
{
	if (!last_one)
		game->fireballs = ball->next;
	else
		last_one->next = ball->next;
	free(ball->sprite.img);
	free(ball);
}

static void	draw_fireball(t_fireball *fireball, t_game *game)
{
	int			x;
	int			y;

	x = (fireball->x - game->map.x) * BLOCK_SIZE;
	y = (fireball->y - game->map.y) * BLOCK_SIZE;
	copy_img_to(&game->map.map, &fireball->sprite,
		to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	check_player_collision(fireball->x, fireball->y, game);
}

void	rdf(t_fireball *fireball)
{
	fireball->x += 1;
	fireball->steps += 1;
}

void	render_fireball(t_game *game)
{
	t_fireball	*fireball;
	t_fireball	*last_one;

	fireball = game->fireballs;
	last_one = 0;
	while (fireball)
	{
		if (is_on_map(fireball->x, fireball->y, game))
			draw_fireball(fireball, game);
		if (fireball->steps == 8)
		{
			free_fireball(last_one, fireball, game);
			fireball = last_one;
			if (!fireball)
				fireball = game->fireballs;
			if (!fireball)
				break ;
		}
		else
		{
			rdf(fireball);
		}
		last_one = fireball;
		fireball = fireball->next;
	}
}
