/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:47:48 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:55:57 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		counter;

	nb = n;
	counter = 0;
	if (nb < 0)
	{
		counter += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		counter += ft_putnbr(nb / 10);
	counter += ft_putchar((nb % 10) + '0');
	return (counter);
}
