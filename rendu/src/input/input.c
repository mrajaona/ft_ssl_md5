/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:15:09 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:15:11 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

char	*ft_read_file(const char *path, t_params *p)
{
	char	*line;
	int		fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_printerr(p->exe, path, ERR_OPEN);
		return (NULL);
	}
	line = NULL;
	if (get_next_line(fd, &line, &(p->file_size)) == -1)
	{
		ft_printerr(NULL, path, ERR_GNL);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (line);
}

char	*ft_read_stdin(t_params *p)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line, &(p->file_size)) == -1)
	{
		ft_printerr(p->exe, "stdin", ERR_GNL);
		return (NULL);
	}
	return (line);
}
