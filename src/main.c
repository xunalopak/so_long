/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:55:38 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:55:41 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		w;

	ft_bzero(&game, sizeof(t_game));
	if (argc == 2)
	{
		if (check_map(argv[1], &game))
			game_config(&game);
		else
			return (check_error(INVALID_MAP));
		game_init(&game);
	}
	else
		return (check_error(INVALID_PARAM_NB));
	return (SUCCESS);
}
