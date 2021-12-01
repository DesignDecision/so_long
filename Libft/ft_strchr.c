/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:26 by spax              #+#    #+#             */
/*   Updated: 2021/05/18 14:09:26 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*chs;

	chs = (char *)s;
	while (*chs)
	{
		if (*chs == c)
			return (chs);
		chs++;
	}
	if (*chs == c)
		return (chs);
	return (0);
}
