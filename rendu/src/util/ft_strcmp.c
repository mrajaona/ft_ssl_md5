/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:35:58 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:36:00 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	n;

	n = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[n] == s2[n] && s1[n] && s2[n])
		n = n + 1;
	return (s1[n] - s2[n]);
}
