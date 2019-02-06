#include "util.h"

void		*ft_memalloc(size_t size)
{
	char	*ptr;

	if (size == 0)
		return (NULL);
	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	while (--size != 0)
		ptr[size] = 0;
	ptr[0] = 0;
	return ((void *)ptr);
}
