/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:54 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:56 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_img(t_data *img, char *path, t_game *game)
{
	img->img = mlx_xpm_file_to_image(game->vars.mlx, path, &img->w, &img->h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endin);
}

void	create_img(t_data *img, int w, int h, t_game *game)
{
	img->img = mlx_new_image(game->vars.mlx, w, h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endin);
}
