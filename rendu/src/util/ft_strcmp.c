#include "util.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	n;

	n = 0;
	while (s1[n] == s2[n] && s1[n] && s2[n])
		n = n + 1;
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
