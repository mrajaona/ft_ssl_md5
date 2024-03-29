/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:36:42 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:36:54 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

/*
** return values :
**  1 : line read
**  0 : end
** -1 : error
*/

static void	ft_buf_clr(char *buf, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		buf[i] = 0;
		i++;
	}
}

static void	ft_alloc_line(char **line, size_t len, size_t cpylen)
{
	char	*str;

	if (line == NULL)
		return ;
	if ((str = ft_memalloc(len + 1)) == NULL)
	{
		ft_strdel(line);
		return ;
	}
	if (line != NULL && *line != NULL)
	{
		ft_memcpy(str, (*line), cpylen);
		ft_strdel(line);
	}
	*line = str;
}

static void	ft_get_next_line(t_gnl *gnl, char **line)
{
	char	buf[BUFFER_SIZE + 1];

	while (gnl->rd > 0)
	{
		ft_buf_clr(buf, BUFFER_SIZE + 1);
		gnl->rd = read(gnl->fd, buf, BUFFER_SIZE);
		if (gnl->rd == -1)
		{
			gnl->ret = -1;
			return ;
		}
		gnl->ret = gnl->size > 0 ? 1 : 0;
		gnl->old_size = gnl->size;
		gnl->size += gnl->rd;
		ft_alloc_line(line, gnl->size, gnl->old_size);
		if (line == NULL || *line == NULL)
		{
			gnl->ret = -1;
			return ;
		}
		ft_memcpy(*line + gnl->old_size, buf, (size_t)gnl->rd);
	}
}

int			get_next_line(int const fd, char **line, size_t *size)
{
	t_gnl	gnl;

	if (!line)
		return (-1);
	gnl.fd = fd;
	gnl.size = 0;
	gnl.old_size = 0;
	gnl.rd = 1;
	gnl.ret = 0;
	ft_get_next_line(&gnl, &(*line));
	*size = gnl.size;
	return (gnl.ret);
}
