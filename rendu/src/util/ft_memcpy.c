/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:35:46 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:35:47 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*srcs;
	size_t		i;

	if (src == NULL || dest == NULL)
		return (NULL);
	dst = dest;
	srcs = src;
	i = -1;
	while (++i < n)
		dst[i] = srcs[i];
	return ((void *)dst);
}
