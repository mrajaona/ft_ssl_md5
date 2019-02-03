#include "md5.h"

/*
** creates a 128 bits hash
** empty hash : d41d8cd98f00b204e9800998ecf8427e
**
** check <limits.h> CHAR_BIT for byte size
** check little/big endian
*/

/*
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
*/

static enum e_endian check_endian( void )
{
   unsigned int	i;
   char			*c;

   i = 1;
   c = (char *)&i;
   return (*c ? little : big);
}

void	md5init(t_md5 *context, const char *src)
{
	context->endian = check_endian();
	context->len = ft_strlen(src);
    context->hash[0] = 0x67452301;
    context->hash[1] = 0xefcdab89;
    context->hash[2] = 0x98badcfe;
    context->hash[3] = 0x10325476;
	context->bits[0] = 0;
	context->bits[1] = 1;
}

char	*ft_md5(const char *src)
{
	t_md5	context;

	md5init(&context, src);
	return ("md5 !");
}

