/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:26:11 by fsousa            #+#    #+#             */
/*   Updated: 2025/07/27 16:35:51 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	concatlen;
	char	*ptr;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	concatlen = s1len + s2len;
	ptr = malloc(concatlen + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1len + 1);
	ft_strlcat(ptr, s2, concatlen + 1);
	return (ptr);
}
