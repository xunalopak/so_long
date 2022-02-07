/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:49 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:51 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	int		index;

	index = 0;
	if (nmemb * size > INT_MAX)
	{
		errno = 12;
		return (0);
	}
	r = malloc(nmemb * size);
	if (r)
	{
		while (index < nmemb * size)
		{
			((char *)r)[index] = 0;
			index++;
		}
		return (r);
	}
	return (0);
}
