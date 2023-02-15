/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:56:46 by tmoumni           #+#    #+#             */
/*   Updated: 2023/02/15 18:19:38 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(250);
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		while (av[2][i])
		{
			send_signal(av[2][i], pid);
			i++;
		}
	}
	else
	{
		ft_putstr("\033[1;31mUsage: ./client [PID] [Message]\033[0m\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
