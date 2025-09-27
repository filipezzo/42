/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:18:45 by fsousa            #+#    #+#             */
/*   Updated: 2025/08/07 15:54:17 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(va_list args)
{
	void	*ptr;
	int		counter;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	counter = write(1, "0x", 2);
	counter += ft_puthex((unsigned long) ptr, 1);
	return (counter);
}
