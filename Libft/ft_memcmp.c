/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   @filename.c@                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:35:20 by spax              #+#    #+#             */
/*   Updated: 2021/05/17 08:35:20 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*stra;
	const unsigned char	*strb;

	stra = (const unsigned char *)str1;
	strb = (const unsigned char *)str2;
	while (n > 0)
	{
		n--;
		if (*stra != *strb)
			return (*stra - *strb);
		if (n != 0)
		{
			stra++;
			strb++;
		}
	}
	return (0);
}
