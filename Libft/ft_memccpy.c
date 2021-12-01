/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   @filename.c@                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:34:52 by spax              #+#    #+#             */
/*   Updated: 2021/05/17 08:34:52 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void	*ft_memccpy(const void *dest, const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			i;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*cdest = *csrc;
		if (*cdest == (unsigned char)c)
			return (cdest + 1);
		cdest++;
		csrc++;
		i++;
	}
	cdest++;
	if (i < n)
		return (cdest);
	else
		return (NULL);
}
