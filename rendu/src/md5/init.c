/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:15:42 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:15:43 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

/*
** start padding 1 bit of value '1'
** end padding with 64 bits representing the source size
** complete with 0 until total is a multiple of 512 bits
*/

static void	ft_pad_src(t_md5 *context, const char *src)
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
	ft_memcpy(context->src + i, (const void *)&bits, 8);
	context->n_chunks = padded_len / 64;
}

void		md5_init(t_md5 *context, const char *src, size_t size)
{
	context->len = size == 0 ? ft_strlen(src) : size;
	ft_pad_src(context, src);
	context->hash[0] = 0x67452301;
	context->hash[1] = 0xefcdab89;
	context->hash[2] = 0x98badcfe;
	context->hash[3] = 0x10325476;
}
