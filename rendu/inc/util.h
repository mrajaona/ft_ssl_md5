/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:10:43 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:10:51 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
**	GNL
*/

# define BUFFER_SIZE 4096

typedef struct	s_gnl
{
	int			fd;
	size_t		size;
	size_t		old_size;
	ssize_t		rd;
	int			ret;
}				t_gnl;

/*
**	Functions
*/

unsigned int	right_rot(unsigned int word, unsigned int amount);
unsigned int	left_rot(unsigned int word, unsigned int amount);
void			ft_strcpy(const char *src, char *dest);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_strdel(char **as);
void			*ft_memalloc(size_t size);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			ft_gethex(const unsigned int i);
unsigned int	ft_endian_uint(unsigned int src);
size_t			ft_endian_size_t(size_t src);
int				get_next_line(int const fd, char **line, size_t *size);

#endif
