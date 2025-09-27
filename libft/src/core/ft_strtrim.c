/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:40:31 by fsousa            #+#    #+#             */
/*   Updated: 2025/07/31 10:09:19 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		ptrlen;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_is_in_set(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	ptrlen = (end - start + 1);
	ptr = malloc(ptrlen + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, ptrlen + 1);
	return (ptr);
}

static int	ft_is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
