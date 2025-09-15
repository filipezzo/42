/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:07:25 by fsousa            #+#    #+#             */
/*   Updated: 2025/09/15 11:05:52 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*
 * our global struct is used for getting and saving the information
 * about the bits that we are receiving and rebuild the entire char.
*/
static t_data	g_data;

static void	handler(int signal, siginfo_t *info, void *context)
{
	(void) context;
	if (signal == SIGUSR2)
		g_data.c |= (1 << g_data.bit);
	g_data.bit++;
	if (g_data.bit == 8)
	{
		if (g_data.c == '\0')
		{
			write(1, "\n", 1);
			if (info && info->si_pid > 0)
				kill(info->si_pid, SIGUSR2);
		}
		else
		{
			write(1, &g_data.c, 1);
		}
		g_data.c = 0;
		g_data.bit = 0;
	}
	if (info && info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_data.c = 0;
	g_data.bit = 0;
	write(1, "server id - ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
