/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:30:32 by fsousa            #+#    #+#             */
/*   Updated: 2025/09/27 10:42:21 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(va_list args)
{
	unsigned int	unsigned_decimal;
	int				counter;

	unsigned_decimal = va_arg(args, unsigned int);
	counter = ft_putunsigned(unsigned_decimal);
	return (counter);
}
