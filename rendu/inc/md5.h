/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:05:24 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:05:28 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"
# include "output.h"
# include "util.h"

typedef struct			s_md5
{
	size_t				len;
	char				*src;
	size_t				n_chunks;
	unsigned int		hash[4];
}						t_md5;

typedef struct			s_calc_md5
{
	char				*chunk;
	unsigned int		word;
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
}						t_calc_md5;

/*
**	Functions
*/

char					*ft_md5(const char *src, size_t size);
void					md5_init(t_md5 *context, const char *src, size_t size);
void					md5_calc_loop(t_calc_md5 *calc);
unsigned int			md5_round_f(t_calc_md5 *calc, unsigned int j);
unsigned int			md5_round_g(t_calc_md5 *calc, unsigned int j);
unsigned int			md5_round_h(t_calc_md5 *calc, unsigned int j);
unsigned int			md5_round_i(t_calc_md5 *calc, unsigned int j);
char					*md5_tostr(unsigned int hash[4]);
#endif
