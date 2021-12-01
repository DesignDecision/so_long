/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 06:39:27 by spax              #+#    #+#             */
/*   Updated: 2021/02/21 10:31:48 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_count_digit(int nb)
{
	int	d;

	d = 1;
	while (nb > 9)
	{
		nb /= 10;
		d *= 10;
	}
	return (d);
}

void	ft_calc(int nb, int digits, int fd)
{
	int	i;

	while (digits > 0)
	{
		i = nb / digits;
		ft_putchar(i + 48, fd);
		nb %= digits;
		digits /= 10;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	digits;

	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-', fd);
			nb *= -1;
		}
		if (nb < 10)
		{
			nb += 48;
			ft_putchar(nb, fd);
		}
		else
		{
			digits = ft_count_digit(nb);
			ft_calc(nb, digits, fd);
		}
	}
}
