#include "input.h"

char *ft_read_stdin( void )
{
	char *line;

	if (get_next_line(0, &line) == -1)
	{
		ft_printerr("GNL error.");
		return (NULL);
	}
	return ( line );
}