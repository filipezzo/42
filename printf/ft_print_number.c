/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:29:46 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:09:59 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(va_list args)
{
	int	counter;
	int	number;

	number = va_arg(args, int);
	counter = ft_putnbr(number);
	return (counter);
}
