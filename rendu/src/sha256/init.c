#include "sha256.h"

/*
** start padding 1 bit of value '1'
** end padding with 64 bits representing the source size (big endian)
** complete with 0 until total is a multiple of 512 bits
**
*/
static void	ft_pad_src(t_sha256 *context, const char *src)
{
	size_t	padded_len;
	size_t	i;
	size_t	bits;

	padded_len = context->len + 1 + 8;
	while (padded_len % 64 != 0)
		padded_len++;
	context->src = (char *)ft_memalloc(padded_len);
	if (context->src == NULL)
	{
		ft_printerr(NULL, NULL, "ERROR: could not allocate.");
		return ;
	}
	ft_memcpy(context->src, src, context->len);
	i = context->len;
	context->src[i] = 0x80;
	i = padded_len - 8;
	bits = context->len * 8;
	bits = ft_endian_size_t(bits);
	ft_memcpy(context->src + i, (const void *)&bits, 8);
	context->n_chunks = padded_len / 64;
}

void		sha256_init(t_sha256 *context, const char *src, size_t size)
{
	context->len = size == 0 ? ft_strlen(src) : size;
	ft_pad_src(context, src);

	context->hash[0] = 0x6a09e667;
	context->hash[1] = 0xbb67ae85;
	context->hash[2] = 0x3c6ef372;
	context->hash[3] = 0xa54ff53a;
	context->hash[4] = 0x510e527f;
	context->hash[5] = 0x9b05688c;
	context->hash[6] = 0x1f83d9ab;
	context->hash[7] = 0x5be0cd19;
}