#ifndef OUTPUT_H
# define OUTPUT_H

# include "ft_ssl.h"
# include "util.h"
# include <unistd.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define NULLSTR "(null)"
# define USAGE "usage: ft_ssl command [command opts] [command args]"
# define ERR_CMD "invalid command."
# define ERR_FLAG "invalid flag."
# define ERR_OPT_S "Error: no argument for option -s."

/*
**	Functions
*/

void	ft_usage( void );
void	ft_print(const char *str, bool endline);
void	ft_printerr(const char *str);
void	ft_print_console(const char *hash, const char *src, t_params *params);
void	ft_print_checksum(const char *str, const char *src, t_params *params);

#endif
