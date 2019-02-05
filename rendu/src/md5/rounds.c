#include "md5.h"

const unsigned int	md5_const_table[64] = {
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

const unsigned int	md5_const_f[4] = {7, 12, 17, 22};
const unsigned int	md5_const_g[4] = {5, 9, 14, 20};
const unsigned int	md5_const_h[4] = {4, 11, 16, 23};
const unsigned int	md5_const_i[4] = {6, 10, 15, 21};

static unsigned int	ft_shift(unsigned int to_shift, unsigned int amount)
{
	unsigned int a;
	unsigned int b;

	a = to_shift << amount;
	b = to_shift >> (32 - amount);
	return (a | b);
}

unsigned int		ft_round_f(t_calc *calc, unsigned int j)
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

unsigned int		ft_round_g(t_calc *calc, unsigned int j)
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

unsigned int		ft_round_h(t_calc *calc, unsigned int j)
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

unsigned int		ft_round_i(t_calc *calc, unsigned int j)
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