/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:24:38 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:09:59 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, int islower)
{
	char	*range;
	int		counter;

	if (islower)
		range = "0123456789abcdef";
	else
		range = "0123456789ABCDEF";
	counter = 0;
	if (nb >= 16)
		counter += ft_puthex(nb / 16, islower);
	counter += ft_putchar(range[nb % 16]);
	return (counter);
}
