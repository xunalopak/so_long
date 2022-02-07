/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:36 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:38 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src && *src != '\n')
	{	
		*dest = *src;
		dest++;
		src++;
	}
}
