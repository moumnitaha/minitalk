/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:16:23 by tmoumni           #+#    #+#             */
/*   Updated: 2023/02/17 14:51:29 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_client_pid;

int	pow_two(int n)
{
	if (!n)
		return (1);
	return (2 * pow_two(n - 1));
}

void	sighandle(int signum, siginfo_t *sig_data, void *t)
{
	static int	data;
	static int	bit;

	(void)t;
	if (g_client_pid != sig_data->si_pid)
	{
		data = 0;
		bit = 0;
	}
	if (signum == SIGUSR1)
		data += pow_two(bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(data);
		data = 0;
		bit = 0;
	}
	g_client_pid = sig_data->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;
	int					acknowledge;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = &sighandle;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	acknowledge = 0;
	while (1)
	{
		if (acknowledge != g_client_pid)
		{
			acknowledge = g_client_pid;
			kill(g_client_pid, SIGUSR1);
		}
		pause();
	}
	return (0);
}
