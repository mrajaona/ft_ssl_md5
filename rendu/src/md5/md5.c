#include "md5.h"

/*
** creates a 128 bits hash
** empty hash : d41d8cd98f00b204e9800998ecf8427e
**
** check <limits.h> CHAR_BIT for byte size
** check little/big endian
*/

const int md5_const_table[64] = {
	//f
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	//g
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	//h
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	//i
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

static void ulToByte(unsigned long long size, char *buf) // TODO : check unsigned long = 64 bits
{
	int	i;
	int	shift;

	i = 0;
	shift = 3 * 8;
	while (i < 4)
	{
		buf[i] = (unsigned char)((size >> shift) & 0xff);
		shift -= 8;
		i++;
	}
}

static unsigned long	ft_f(unsigned long b, unsigned long c, unsigned long d)
{
	return ((b & c) | (~b & d));
}
static unsigned long	ft_g(unsigned long b, unsigned long c, unsigned long d)
{
	return ((b & d) | (c & ~d));
}
static unsigned long	ft_h(unsigned long b, unsigned long c, unsigned long d)
{
	return (b ^ c ^ d);
}
static unsigned long	ft_i(unsigned long b, unsigned long c, unsigned long d)
{
	return (c ^ (b | ~d));
}

static void calculate(t_md5 *context)
{
	char			chunk[64];
	unsigned int	sub[6]; // abcd fg
	unsigned int	tmp;
	char			*src;
	unsigned int	i;
	unsigned int	j;

	src = context->src;
	i = 0;
	while (i < context->n_chunks)
	{
		// init chunk
    	sub[0] = context->hash[0]; //a
    	sub[1] = context->hash[1]; //b
    	sub[2] = context->hash[2]; //c
    	sub[3] = context->hash[3]; //d

    	ft_memcpy(src, chunk, 64);

		j = 0;
		while (j < 64)
		{
			// fghi
			if (j < 16)
			{
				sub[4] = ft_f(sub[1], sub[2], sub[3]);
				sub[5] = j;
			}
			else if (j < 32)
			{
				sub[4] = ft_g(sub[1], sub[2], sub[3]);
				sub[5] = (5 * i + 1) % 16;
			}
			else if (j < 48)
			{
				sub[4] = ft_h(sub[1], sub[2], sub[3]);
				sub[5] = (3 * i + 5) % 16;
			}
			else
			{
				sub[4] = ft_i(sub[1], sub[2], sub[3]);
				sub[5] = (7 * i) % 16;
			}

			sub[4] += sub[0] + md5_const_table[j] + chunk[sub[5]];

			j++;

			// rotate
			tmp = sub[0];
			sub[0] = sub[3];
			sub[3] = sub[2];
			sub[2] = sub[1];
			sub[1] = tmp;
		}

		// add to context->hash
    	context->hash[0] += sub[0];
    	context->hash[1] += sub[1];
    	context->hash[2] += sub[2];
    	context->hash[3] += sub[3];

    	src += 64;
		i++;
	}
}

static void				ft_pad_src(t_md5 *context, const char *src)
{
	size_t				padded_len; // in bytes
	size_t				i;
	union u_bits		bits;

	padded_len = context->len + 1 + 8; // 1 bit for padding init && 64 bits for len
	while (padded_len % 64 != 0) // % 512 bits
		padded_len++;
	context->src = ft_memalloc(padded_len);
	if (context->src == NULL)
		return ; // TODO : Error
	ft_strcpy(src, &context->src);
	i = context->len;
	context->src[i] = (1 << 7);
	i = padded_len - 8;
	bits.ull = context->len * 8;
	ulToByte(bits.ul[0], context->src + i);
	ulToByte(bits.ul[1], context->src + i);
	context->n_chunks = padded_len / 64;
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
	ft_pad_src(context, src);
    context->hash[0] = 0x67452301;
    context->hash[1] = 0xefcdab89;
    context->hash[2] = 0x98badcfe;
    context->hash[3] = 0x10325476;
}

#include <stdio.h>
char	*ft_md5(const char *src)
{
	t_md5	context;

	md5init(&context, src);
	if (context.src == NULL)
		return (NULL);
	calculate(&context);
	printf("%zx %zx %zx %zx\n", context.hash[0], context.hash[1], context.hash[2], context.hash[3]);
	ft_strdel(&context.src);
	return ("md5 !");
}

