#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)

{
	char	*dst;
	size_t	len;

	len = (ft_strlen(s1) + 1);
	dst = malloc(sizeof (char) * len);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len);
	return (dst);
}
