#include "md5.h"

static char gethex(const unsigned int i)
{
	if (i < 10)
		return (i + '0');
	else if (i <= 16)
		return (i - 10 + 'a');
	else
		return (0);
}

static void	mask(const unsigned int src, char *s, size_t i)
{
	unsigned int n;

	n = (src & (0xff << (8 * i))) >> (8 * i);
	*s = gethex((n & 0xf0) >> 4);
	*(s + 1) = gethex(n & 0x0f);
}

char		*tostr(unsigned int hash[4])
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