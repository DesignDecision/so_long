/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   @filename.c@                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:35:45 by spax              #+#    #+#             */
/*   Updated: 2021/05/17 08:35:45 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	int				i;

	if (!dest && !src)
		return (NULL);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
		i++;
	}
	return (dest);
}
