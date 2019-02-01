#include "input.h"

char	*ft_read_file(const char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	// TODO : read tout le truc
	if (get_next_line(fd, &line) == -1)
	{
		ft_printerr("GNL error.");
		close(fd);
		return (NULL);
	}
	close(fd);
	return (line);
}

char	*ft_read_stdin( void )
{
	char	*line;

	if (get_next_line(0, &line) == -1)
	{
		ft_printerr("GNL error.");
		return (NULL);
	}
	return (line);
}