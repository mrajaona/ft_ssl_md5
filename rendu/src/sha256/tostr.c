/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:17:41 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:17:42 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

static void	mask(const unsigned int src, char *s, size_t i)
{
	unsigned int n;

	n = (src & (0xff << (8 * i))) >> (8 * i);
	*s = ft_gethex((n & 0xf0) >> 4);
	*(s + 1) = ft_gethex(n & 0x0f);
}

char		*sha256_tostr(unsigned int hash[8])
{
	char	*str;
	char	*s;
	size_t	n_hash;
	size_t	i;

	str = ft_memalloc(64 + 1);
	if (str == NULL)
		return (NULL);
	n_hash = 0;
	s = str;
	while (n_hash < 8)
	{
		i = 0;
		while (i < 4)
		{
			mask(ft_endian_uint(hash[n_hash]), s, i);
			s += 2;
			i++;
		}
		n_hash++;
	}
	return (str);
}
