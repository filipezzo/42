/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:28:14 by fsousa            #+#    #+#             */
/*   Updated: 2025/07/27 16:28:41 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	words;
	char	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (!in_word && *s != c)
		{
			words++;
			in_word = 1;
		}
		if (*s == c)
			in_word = 0;
		s++;
	}
	return (words);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*create_word(const char *s, char c)
{
	char	*word;

	word = ft_substr(s, 0, get_word_len(s, c));
	return (word);
}

static char	**fill_arr(char **arr, const char *s, char c, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
	{
		while (*s == c)
			s++;
		arr[i] = create_word(s, c);
		if (!arr[i])
		{
			while (i)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		s += get_word_len(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	arr_size;

	arr_size = word_count(s, c);
	arr = malloc((arr_size + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_arr(arr, s, c, arr_size));
}
