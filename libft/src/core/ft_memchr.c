/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:30:55 by fsousa            #+#    #+#             */
/*   Updated: 2025/07/24 10:10:04 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) s;
	ch = (unsigned char) c;
	while (i < n)
	{
		if (*ptr == ch)
		{
			return ((void *) ptr);
		}
		i++;
		ptr++;
	}
	return (NULL);
}
