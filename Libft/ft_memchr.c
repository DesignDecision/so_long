/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   @filename.c@                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:35:13 by spax              #+#    #+#             */
/*   Updated: 2021/05/17 08:35:13 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*chs;

	chs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*chs == (unsigned char)c)
		{
			return (chs);
		}
		chs++;
		i++;
	}
	return (NULL);
}
