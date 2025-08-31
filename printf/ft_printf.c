/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:52:58 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:47:29 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	which_ft_execute(va_list args, char option)
{
	if (option == 'c')
		return (ft_print_char(args));
	else if (option == '%')
		return (ft_putchar('%'));
	else if (option == 's')
		return (ft_print_string(args));
	else if (option == 'i' || option == 'd')
		return (ft_print_number(args));
	else if (option == 'u')
		return (ft_print_unsigned_decimal(args));
	else if (option == 'p')
		return (ft_print_pointer(args));
	else if (option == 'x')
		return (ft_print_hex(args, 1));
	else if (option == 'X')
		return (ft_print_hex(args, 0));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;

	va_start(args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			counter += which_ft_execute(args, format[i + 1]);
			i += 2;
		}
		else
		{
			counter += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (counter);
}
