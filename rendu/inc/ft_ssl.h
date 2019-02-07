/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:02:03 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:02:39 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>

# define TRUE 1
# define FALSE 0

# define N_CMDS 2

typedef int			t_bool;

typedef struct		s_cmd
{
	char			*name;
	char			*(*fn)(const char *, size_t size);
}					t_cmd;

typedef struct		s_params
{
	char			*exe;
	int				pos;
	t_bool			std_in;
	t_bool			opt_p;
	t_bool			opt_q;
	t_bool			opt_r;
	t_bool			opt_s;
	t_cmd			cmd;
	size_t			file_size;
}					t_params;

#endif
