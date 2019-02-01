#ifndef PARSER_H
# define PARSER_H

# include "ft_ssl.h"
# include "util.h"
# include "output.h"
# include "md5.h"
# include "sha256.h"

typedef char	byte;

# define TRUE 1
# define FALSE 0

# define OPT(opt) opt == 'p' || opt == 'q' || opt == 'r' || opt == 's'

/*
**	Functions
*/

void	ft_ssl_parse_args(const int ac, const char **av, t_params *params);

#endif
