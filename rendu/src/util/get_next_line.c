/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:04:33 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/17 09:01:23 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

/*
** return values :
**  1 : line read
**  0 : end
** -1 : error
*/

static int	ft_end(int ret, const size_t size)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && size > 0)
		return (1);
	if (ret == 0 && size == 0)
		return (0);
	return (0);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

static char	*ft_alloc(char **line, size_t len)
{
	char	*str;

	if ((str = malloc(len + BUFFER_SIZE)) == NULL)
	{
		if (line != NULL && *line != NULL)
		{
			free(*line);
			*line = NULL;
		}
		return (NULL);
	}
	if (len == 0)
		return (str);
	ft_strncpy(str, (*line), len);
	free(*line);
	return (str);
}

static int	ft_get_next_line(t_gnl *gnl, char **line)
{
	char	c;

	while (42)
	{
		if (((*line) = ft_alloc(line, gnl->size)) == NULL)
			return (-1);
		while (gnl->size < BUFFER_SIZE * gnl->n)
		{
			gnl->ret = read(gnl->fd, &c, 1);
			(*line)[gnl->size] = '\0';
			if (gnl->ret > 0)
			{
				if (c == DEL)
					return (1);
				(*line)[gnl->size] = c;
			}
			else
				return (ft_end(gnl->ret, gnl->size));
			gnl->size = gnl->size + 1;
		}
		(*line)[gnl->size] = '\0';
		gnl->n = gnl->n + 1;
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	t_gnl	gnl;

	if (!line)
		return (-1);
	gnl.fd = fd;
	gnl.size = 0;
	gnl.n = -1;
	gnl.ret = 0;
	return (ft_get_next_line(&gnl, &(*line)));
}
