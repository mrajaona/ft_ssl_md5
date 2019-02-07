/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:24 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:07:27 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_ssl.h"
# include "util.h"
# include "output.h"
# include "md5.h"
# include "sha256.h"

# define TRUE 1
# define FALSE 0

/*
**	Functions
*/

t_bool			ft_ssl_parse(const int ac, const char **av, t_params *p);

#endif
