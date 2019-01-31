#ifndef OUTPUT_H
# define OUTPUT_H

# include "util.h"
# include <unistd.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define NULLSTR "(null)"
# define USAGE "usage: ft_ssl command [command opts] [command args]"
# define ERR_CMD "invalid command."
# define ERR_FLAG "invalid flag."

/*
**	Functions
*/

void	ft_usage( void );
void	ft_print(const char *str);
void	ft_printerr(const char *str);

#endif
