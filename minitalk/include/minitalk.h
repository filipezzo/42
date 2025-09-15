/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:03:59 by fsousa            #+#    #+#             */
/*   Updated: 2025/09/14 10:56:30 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_atoi(char *str);

typedef struct s_data {
	unsigned char	c;
	int				bit;

}	t_data;

#endif