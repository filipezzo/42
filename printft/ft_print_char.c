/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:59:04 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:09:59 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	int	c;
	int	result;

	c = 0;
	result = 0;
	c = va_arg(args, int);
	result = ft_putchar(c);
	return (result);
}
