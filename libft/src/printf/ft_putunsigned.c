/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:36:23 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:11:00 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb >= 10)
		counter += ft_putunsigned(nb / 10);
	counter += ft_putchar((nb % 10) + '0');
	return (counter);
}
