/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:33:59 by tmoumni           #+#    #+#             */
/*   Updated: 2023/02/13 18:43:41 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long int	nbr;

	nbr = (long int)n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
}

int	ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		index;
	long	result;

	index = 0;
	sign = 1;
	result = 0;
	while (str[index] && ft_iswhitespace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
		index++;
	if (index > 0 && str[index - 1] == '-')
		sign = -1;
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
		result = result * 10 + (str[index++] - '0');
	return (sign * result);
}
