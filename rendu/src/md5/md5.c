#include "md5.h"

/*
** creates a 128 bits hash
** empty hash : d41d8cd98f00b204e9800998ecf8427e
**
** check <limits.h> CHAR_BIT for byte size
** check little/big endian
*/

#include "output.h" // DEBUG
const unsigned int md5_const_table[64] = {
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

const unsigned int md5_const_f[4] = {7, 12, 17, 22};
const unsigned int md5_const_g[4] = {5, 9, 14, 20};
const unsigned int md5_const_h[4] = {4, 11, 16, 23};
const unsigned int md5_const_i[4] = {6, 10, 15, 21};

static unsigned int	ft_shift(unsigned int to_shift, unsigned int amount)
{
	unsigned int a;
	unsigned int b;

	a = to_shift << amount;
	b = to_shift >> (32 - amount);
	return (a | b);
}

static unsigned int	ft_round_f(t_calc *calc, unsigned int j)
{
	unsigned int	w;
	unsigned int	ret;

	w = (1 * j + 0) % 16;
	calc->word = *((unsigned int *)(calc->chunk) + w);

	ret = (calc->b & calc->c) | (~(calc->b) & calc->d);
	ret = ft_shift(ret + calc->a + md5_const_table[j] + calc->word, md5_const_f[j % 4]);
	ret = calc->b + ret;

	return (ret);
}

static unsigned int	ft_round_g(t_calc *calc, unsigned int j)
{
	unsigned int	w;
	unsigned int	ret;

	w = (5 * j + 1) % 16;
	calc->word = *((unsigned int *)(calc->chunk) + w);

	ret = (calc->d & calc->b) | (~(calc->d) & calc->c);
	ret = ft_shift(ret + calc->a + md5_const_table[j] + calc->word, md5_const_g[j % 4]);
	ret = calc->b + ret;

	return (ret);
}

static unsigned int	ft_round_h(t_calc *calc, unsigned int j)
{
	unsigned int	w;
	unsigned int	ret;

	w = (3 * j + 5) % 16;
	calc->word = *((unsigned int *)(calc->chunk) + w);

	ret = (calc->b ^ calc->c ^ calc->d);
	ret = ft_shift(ret + calc->a + md5_const_table[j] + calc->word, md5_const_h[j % 4]);
	ret = calc->b + ret;

	return (ret);
}

static unsigned int	ft_round_i(t_calc *calc, unsigned int j)
{
	unsigned int	w;
	unsigned int	ret;

	w = (7 * j) % 16;
	calc->word = *((unsigned int *)(calc->chunk) + w);

	ret = (calc->c ^ (calc->b | ~(calc->d)));
	ret = ft_shift(ret + calc->a + md5_const_table[j] + calc->word, md5_const_i[j % 4]);
	ret = calc->b + ret;

	return (ret);
}

static void calculate(t_md5 *context)
{
	t_calc			calc;
	unsigned int	tmp;
	size_t	i;
	size_t	j;

	calc.chunk = context->src;
	i = 0;
	while (i < context->n_chunks)
	{
		// init chunk
		calc.a = context->hash[0];
		calc.b = context->hash[1];
		calc.c = context->hash[2];
		calc.d = context->hash[3];

		j = 0;
		while (j < 64)
		{
			if (j < 16)
				tmp = ft_round_f(&calc, j);
			else if (j < 32)
				tmp = ft_round_g(&calc, j);
			else if (j < 48)
				tmp = ft_round_h(&calc, j);
			else
				tmp = ft_round_i(&calc, j);
			calc.a = calc.d;
			calc.d = calc.c;
			calc.c = calc.b;
			calc.b = tmp;
			j++;
		}

		// add to context->hash
		context->hash[0] = calc.a + context->hash[0];
		context->hash[1] = calc.b + context->hash[1];
		context->hash[2] = calc.c + context->hash[2];
		context->hash[3] = calc.d + context->hash[3];

		i++;
		calc.chunk += 64;
	}
}

static void				ft_pad_src(t_md5 *context, const char *src)
{
	size_t	padded_len; // in bytes
	size_t	i;
	size_t	bits;

	padded_len = context->len + 1 + 8; // 1 bit for padding init && 64 bits for len
	while (padded_len % 64 != 0) // % 512 bits
		padded_len++;

	ft_print(src, TRUE); // ok
	context->src = (char *)ft_memalloc(padded_len); // <-------- ?????
	ft_print(src, TRUE); // ng if malloc

	if (context->src == NULL)
	{
		ft_printerr("ERROR: could not allocate.");
		return ; // TODO : Error
	}
	/*
	else // DEBUG
	{
		ft_print("freeing -----------------", TRUE); // ng if malloc
		free(context->src);
		context->src = NULL;
		ft_print(src, TRUE);
		return ;
	}
	*/
	ft_memcpy(context->src, src, context->len);
	i = context->len;
	context->src[i] = 0x80;
	i = padded_len - 8;
	bits = context->len * 8;
	ft_memcpy(context->src + i, (const void *)&bits, 8);
	context->n_chunks = padded_len / 64;
}

static char gethex(unsigned int i)
{
	if (i < 10)
		return (i + '0');
	else if (i <= 16)
		return (i - 10 + 'a');
	else
		return (0);
}

static char	*tostr(unsigned int hash[4])
{
	char	*str;
	char	*s;
	size_t	h;
	size_t	i;

	str = ft_memalloc(32 + 1);
	if (str == NULL)
		return (NULL);
	h = 0;
	s = str;
	while (h < 4)
	{
		i = 0;
		while (i < 4)
		{
			// NORME

			unsigned int src = hash[h];
			unsigned int mask = 0xff << (8 * i);
			unsigned int masked = src & mask;
			unsigned int n = masked >> (8 * i);

			unsigned int m1 = 0xf0;
			unsigned int m2 = 0x0f;

			*s = gethex((n & m1) >> 4);
			*(s + 1) = gethex(n & m2);
			s += 2;
			i++;
		}
		h++;
	}
	return (str);
}

static void	md5init(t_md5 *context, const char *src)
{
	context->len = ft_strlen(src);
	ft_pad_src(context, src);
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
	calculate(&context);
	ft_strdel(&context.src);
	return (tostr(context.hash));
}
