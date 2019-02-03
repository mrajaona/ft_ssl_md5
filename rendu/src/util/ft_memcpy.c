#include "util.h"

void			*ft_memcpy(void *str, const void *src, size_t n)
{
	char		*dst;
	const char	*srcs;
	size_t		i;

	dst = str;
	srcs = src;
	i = -1;
	while (++i < n)
		dst[i] = srcs[i];
	return ((void *)dst);
}
