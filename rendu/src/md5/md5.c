/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:28:09 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:28:10 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static void			calculate(t_md5 *context)
{
	t_calc_md5	calc;
	size_t		i;

	calc.chunk = context->src;
	i = 0;
	while (i < context->n_chunks)
	{
		calc.a = context->hash[0];
		calc.b = context->hash[1];
		calc.c = context->hash[2];
		calc.d = context->hash[3];
		md5_calc_loop(&calc);
		context->hash[0] = calc.a + context->hash[0];
		context->hash[1] = calc.b + context->hash[1];
		context->hash[2] = calc.c + context->hash[2];
		context->hash[3] = calc.d + context->hash[3];
		i++;
		calc.chunk += 64;
	}
}

char				*ft_md5(const char *src, size_t size)
{
	t_md5	context;

	md5_init(&context, src, size);
	if (context.src == NULL)
		return (NULL);
	calculate(&context);
	ft_strdel(&context.src);
	return (md5_tostr(context.hash));
}
