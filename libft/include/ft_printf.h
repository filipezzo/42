/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:56:50 by fsousa            #+#    #+#             */
/*   Updated: 2025/09/27 10:42:06 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_puthex(unsigned long nb, int islower);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int nb);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_print_char(va_list args);
int		ft_print_hex(va_list args, int flag);
int		ft_print_string(va_list args);
int		ft_print_number(va_list args);
int		ft_print_unsigned_decimal(va_list args);
int		ft_print_pointer(va_list args);
#endif 