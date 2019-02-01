#include "md5.h"

/*
** creates a 128 bits hash
** empty hash : d41d8cd98f00b204e9800998ecf8427e
**
** check <limits.h> CHAR_BIT for byte size
*/

static unsigned long	F(unsigned long B, unsigned long C, unsigned long D)
{
	return ((B & C) | (~B & D));
}
static unsigned long	G(unsigned long B, unsigned long C, unsigned long D)
{
	return ((B & D) | (C & ~D));
}
static unsigned long	H(unsigned long B, unsigned long C, unsigned long D)
{
	return (B ^ C ^ D);
}
static unsigned long	I(unsigned long B, unsigned long C, unsigned long D)
{
	return (C ^ (B | ~D));
}

char	*ft_md5(const char *src)
{
	unsigned long *hash;

	(void)src;
	return ("md5 !");
}

