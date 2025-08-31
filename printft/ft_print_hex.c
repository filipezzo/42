/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:49:38 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:09:59 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(va_list args, int flag)
{
	int				counter;
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	counter = ft_puthex((unsigned long)hex, flag);
	return (counter);
}
