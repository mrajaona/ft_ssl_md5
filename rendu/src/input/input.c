#include "input.h"

char	*ft_read_file(const char *path, size_t *size)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	line = NULL;
	if (get_next_line(fd, &line, size) == -1)
	{
		ft_printerr("GNL error.");
		close(fd);
		return (NULL);
	}
	close(fd);
	return (line);
}

char	*ft_read_stdin(size_t *size)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line, size) == -1)
	{
		ft_printerr("GNL error.");
		return (NULL);
	}
	return (line);
}