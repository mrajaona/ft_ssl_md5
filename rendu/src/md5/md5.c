#include "md5.h"

/*
** creates a 128 bits hash
** empty hash : d41d8cd98f00b204e9800998ecf8427e
**
** check <limits.h> CHAR_BIT for byte size
** check little/big endian
*/

static void uiToByte(unsigned int i, char *buf)
{
	buf[0] = (unsigned char)((i >> 24) & 0xff);
	buf[1] = (unsigned char)((i >> 16) & 0xff);
	buf[2] = (unsigned char)((i >> 8)  & 0xff);
	buf[3] = (unsigned char)(i & 0xff);
}

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

void					ft_pad_src(char **padded, const char *src, size_t len)
{
	size_t			padded_len; // in bytes
	size_t			i;
	unsigned int	bits;

	padded_len = len + 1 + 8; // 1 bit for padding init && 64 bits for len
	while (padded_len % 64 != 0) // % 512 bits
		padded_len++;
	*padded = ft_memalloc(padded_len);
	if (*padded == NULL)
		return ; // TODO : Error
	ft_strcpy(src, padded);
	i = len;
	*padded[i] = (1 << 7);
	i = padded_len - 8;
	bits = (unsigned int)len * 8;
	uiToByte(bits & 0xffffffff, *padded + i);
	uiToByte(bits << 8 & 0xffffffff, *padded + i + 4);
}

static enum e_endian	check_endian( void )
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
	context->src = NULL;
	ft_pad_src(&context->src, src, context->len);
    context->hash[0] = 0x67452301;
    context->hash[1] = 0xefcdab89;
    context->hash[2] = 0x98badcfe;
    context->hash[3] = 0x10325476;
}

char	*ft_md5(const char *src)
{
	t_md5	context;

	md5init(&context, src);
	if (context.src == NULL)
		return (NULL);
	return ("md5 !");
}

