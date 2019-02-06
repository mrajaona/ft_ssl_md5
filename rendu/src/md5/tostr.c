#include "md5.h"

static void	mask(const unsigned int src, char *s, size_t i)
{
	unsigned int n;

	n = (src & (0xff << (8 * i))) >> (8 * i);
	*s = ft_gethex((n & 0xf0) >> 4);
	*(s + 1) = ft_gethex(n & 0x0f);
}

char		*md5_tostr(unsigned int hash[4])
{
	char	*str;
	char	*s;
	size_t	n_hash;
	size_t	i;

	str = ft_memalloc(32 + 1);
	if (str == NULL)
		return (NULL);
	n_hash = 0;
	s = str;
	while (n_hash < 4)
	{
		i = 0;
		while (i < 4)
		{
			mask(hash[n_hash], s, i);
			s += 2;
			i++;
		}
		n_hash++;
	}
	return (str);
}