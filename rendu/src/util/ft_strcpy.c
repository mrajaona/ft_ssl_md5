#include "util.h"

/*
** dest size must be big enough to copy
** src must be '\0' terminated
** '\0' will not be copied
*/
void	ft_strcpy(const char *src, char **dest)
{
	char	*d;

	if (src == NULL || dest == NULL || *dest == NULL)
		return ;
	d = *dest;
	while (*src)
	{
		*d = *src;
		src++;
		d++;
	}
}