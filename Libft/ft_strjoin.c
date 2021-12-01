/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   @filename.c@                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spax <spax@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 08:35:45 by spax              #+#    #+#             */
/*   Updated: 2021/06/01 08:35:45 by spax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include<string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pre;
	int		s1len;
	int		s2len;
	int		full_len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	full_len = s1len + s2len;
	pre = malloc(full_len + 1);
	if (!pre)
		return (NULL);
	ft_strlcpy(pre, s1, s1len + 1);
	ft_strlcat(pre + s1len, s2, s2len + 1);
	return (pre);
}
