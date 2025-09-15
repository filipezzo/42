/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:07:18 by fsousa            #+#    #+#             */
/*   Updated: 2025/09/15 11:26:08 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*
** Global variable g_ack is used to synchronize the client with the server.
** It is updated inside the signal handler when an ACK is received.
** the client only sends the next bit after the server's confirmation.
*/
static volatile sig_atomic_t	g_ack = 0;

static void	on_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
	{
		write(1, "end of message\n", 15);
		exit(0);
	}
}

static void	send_char_to_server(pid_t pid, unsigned char c)
{
	int	bit_index;
	int	bit;

	bit_index = 0;
	bit = 0;
	while (bit_index < 8)
	{
		bit = (c >> bit_index) & 1;
		g_ack = 0;
		if (bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_ack == 0)
			pause();
		bit_index++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	unsigned char		c;
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	pid = (pid_t)ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = on_ack;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	while (1)
	{
		c = (unsigned char)argv[2][i];
		send_char_to_server(pid, c);
		if (c == '\0')
			break ;
		i++;
	}
	while (1)
		pause();
	return (0);
}
