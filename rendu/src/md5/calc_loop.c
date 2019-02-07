/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:15:32 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:15:34 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	md5_calc_loop(t_calc_md5 *calc)
{
	unsigned int	tmp;
	size_t			j;

	j = 0;
	while (j < 64)
	{
		if (j < 16)
			tmp = md5_round_f(calc, j);
		else if (j < 32)
			tmp = md5_round_g(calc, j);
		else if (j < 48)
			tmp = md5_round_h(calc, j);
		else
			tmp = md5_round_i(calc, j);
		calc->a = calc->d;
		calc->d = calc->c;
		calc->c = calc->b;
		calc->b = tmp;
		j++;
	}
}
