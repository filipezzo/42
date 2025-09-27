/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:51:10 by fsousa            #+#    #+#             */
/*   Updated: 2025/09/25 13:41:44 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elmt_qtd, size_t elmt_size)
{
	void			*mem;
	size_t			i;
	unsigned char	*tmp;

	if (!elmt_qtd || !elmt_size)
		return (malloc(1));
	if (elmt_size && elmt_qtd > (size_t) - 1 / elmt_size)
		return (NULL);
	mem = malloc(elmt_qtd * elmt_size);
	if (!mem)
		return (NULL);
	tmp = (unsigned char *) mem;
	i = 0;
	while (i < (elmt_qtd * elmt_size))
		tmp[i++] = '\0';
	return (mem);
}
