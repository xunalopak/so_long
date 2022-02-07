/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:59:04 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 19:24:37 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_error(int error)
{
	if (error == INVALID_MAP)
		printf("The given map is invalid!\n");
	if (error == INVALID_PARAM_NB)
		printf("Parameter's number must be 1\n");
	return (error);
}
