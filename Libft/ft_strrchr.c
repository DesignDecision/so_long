/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:03:44 by spax              #+#    #+#             */
/*   Updated: 2021/05/18 17:03:44 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*chs;

	chs = (char *)s;
	while (*chs)
		chs++;
	while (1)
	{
		if (*chs == c)
			return (chs);
		if (chs == s)
			break ;
		chs--;
	}
	return (0);
}
