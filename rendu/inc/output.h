/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:06:44 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:06:47 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include "ft_ssl.h"
# include "util.h"
# include <unistd.h>

# define STDOUT 1
# define STDERR 2

# define NULLSTR "(null)"
# define USAGE "usage: ft_ssl command [command opts] [command args]"
# define ERR_CMD "invalid command."
# define ERR_FLAG "invalid flag."
# define ERR_OPT_S "Error: no argument for option -s."
# define ERR_GNL "Error while reading."
# define ERR_OPEN "No such file or directory."

/*
**	Functions
*/

void	ft_usage(void);
void	ft_print(const char *str, t_bool endline);
void	ft_printerr(const char *exe, const char *arg, const char *str);
void	ft_print_console(const char *hash, const char *src, t_params *p);
void	ft_print_hash(const char *str, const char *src, t_params *p);

#endif
