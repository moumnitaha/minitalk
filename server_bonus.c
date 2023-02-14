/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:16:23 by tmoumni           #+#    #+#             */
/*   Updated: 2023/02/14 16:57:50 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_client_pid;

int	pow_two(int n)
{
	int	result;

	result = 1;
	while (n)
	{
		result *= 2;
		n--;
	}
	return (result);
}

void	sighandle(int signum, siginfo_t *p, void *t)
{
	static int	data;
	static int	bit = 7;

	if (g_client_pid != p->si_pid)
	{
		data = 0;
		bit = 7;
	}
	t = (void *) NULL;
	if (signum == SIGUSR1)
		data += pow_two(bit);
	bit--;
	if (bit == -1)
	{
		ft_putchar(data);
		data = 0;
		bit = 7;
	}
	g_client_pid = p->si_pid;
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
	sa.__sigaction_u.__sa_sigaction = &sighandle;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
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
