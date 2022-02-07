/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:26 by rchampli          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:28 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	size;
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		size = 0;
	else
	{
		size = ft_strlen(&s[start]);
		if (len < size)
			size = len;
	}
	string = (char *) ft_calloc(size + 1, sizeof(char));
	if (!string)
		return (0);
	while (index < size)
	{
		string[index] = s[start + index];
		index++;
	}
	string[index] = '\0';
	return (string);
}
