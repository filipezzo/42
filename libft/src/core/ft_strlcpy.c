/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:40:03 by fsousa            #+#    #+#             */
/*   Updated: 2025/07/31 10:42:36 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;
	size_t	to_copy;

	srclen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (srclen);
	if (srclen < size - 1)
		to_copy = srclen;
	else
		to_copy = size - 1;
	while (i < to_copy)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
