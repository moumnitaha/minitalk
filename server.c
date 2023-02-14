/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:56:39 by tmoumni           #+#    #+#             */
/*   Updated: 2023/02/14 13:51:47 by tmoumni          ###   ########.fr       */
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
	static int	count;
	static int	data;
	static int	bit = 7;

	if (g_client_pid != p->si_pid)
	{
		count = 0;
		data = 0;
		bit = 7;
	}
	t = (void *) NULL;
	if (signum == SIGUSR1)
		data += pow_two(bit);
	bit--;
	count++;
	if (count == 8)
	{
		ft_putchar(data);
		count = 0;
		data = 0;
		bit = 7;
	}
	g_client_pid = p->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.__sigaction_u.__sa_sigaction = &sighandle;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
