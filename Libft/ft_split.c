/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 :42:08 by spax              #+#    #+#               */
/*   Updated: 2021/06/07 10:08:49 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static	int	ft_counter(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter + 1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	pos1;
	int				i;
	int				count_res;
	char			**result;

	pos1 = 0;
	i = 0;
	count_res = 0;
	if (s == NULL)
		return (NULL);
	result = ft_calloc(ft_counter(s, c), sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		pos1 = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			result[count_res] = ft_substr(s, pos1, i - pos1);
		count_res ++;
	}
	return (result);
}
