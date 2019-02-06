#include "sha256.h"

static void update_hash(t_calc_sha256 *calc, unsigned int hash[8])
{
	hash[0] = calc->a + hash[0];
	hash[1] = calc->b + hash[1];
	hash[2] = calc->c + hash[2];
	hash[3] = calc->d + hash[3];
	hash[4] = calc->e + hash[4];
	hash[5] = calc->f + hash[5];
	hash[6] = calc->g + hash[6];
	hash[7] = calc->h + hash[7];
}

static void	calculate(t_sha256 *context)
{
	t_calc_sha256	calc;
	size_t			i;

	calc.chunk = context->src;
	i = 0;
	while (i < context->n_chunks)
	{
		sha256_init_calc(&calc, context->hash);
		sha256_calc_loop(&calc);
		update_hash(&calc, context->hash);
		i++;
		calc.chunk += 64;
	}
}

char	*ft_sha256(const char *src, size_t size)
{
	t_sha256	context;

	sha256_init(&context, src, size);
	if (context.src == NULL)
		return (NULL);
	calculate(&context);
	ft_strdel(&context.src);
	return (sha256_tostr(context.hash));
}