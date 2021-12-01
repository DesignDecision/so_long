/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:46:23 by spax              #+#    #+#             */
/*   Updated: 2021/05/18 08:46:23 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char	*ft_makestr(char c, char *str, int j, int sign)
{
	if (sign == 2)
	{
		str[0] = '-';
		j++;
		sign++;
	}
	str[j] = c;
	j++;
	return (str);
}

static int	ft_count_digit(long long n)
{
	int	d;

	d = 1;
	while (n > 9)
	{
		n /= 10;
		d *= 10;
	}
	return (d);
}

static int	ft_len(long long n)
{
	int	d;

	d = 1;
	while (n > 9)
	{
		n /= 10;
		d++;
	}
	return (d);
}

static char	*ft_calc(long long n, char *str, int digit, int sign)
{
	int	i;
	int	j;

	j = 0;
	while (digit > 0)
	{
		i = n / digit;
		str = ft_makestr(i + 48, str, j, sign);
		n %= digit;
		digit /= 10;
		j++;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char		*str;
	int			digit;
	int			len;
	int			sign;
	long long	n;

	n = (long long)nb;
	sign = 1;
	if (n < 0)
	{
		sign = 2;
		n *= -1;
	}
	digit = ft_count_digit(n);
	len = ft_len(n);
	if (sign == 2)
		len++;
	str = (char *) malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_calc(n, str, digit, sign);
	str[len] = '\0';
	return (str);
}
