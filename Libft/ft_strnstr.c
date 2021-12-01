/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:35:33 by spax              #+#    #+#             */
/*   Updated: 2021/05/18 18:35:33 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && len)
	{
		c = 0;
		while (needle[c] && haystack[c + i] == needle[c] && i + c < len)
		{
			if (needle[c + 1] == '\0')
				return ((char *)haystack + i);
			c++;
		}
		i++;
	}
	return (0);
}
