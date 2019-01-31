#ifndef FT_SSL_H
# define FT_SSL_H

# include "params.h"
# include "util.h"
# include "output.h"
# include "md5.h"
# include "sha256.h"

typedef char	byte;

# define TRUE 1
# define FALSE 0

# define OPT(opt) opt == 'p' || opt == 'q' || opt == 'r' || opt == 's'

# define N_CMDS 2
# define MD5 "md5"
# define N_MD5 0
# define SHA256 "sha256"
# define N_SHA256 1

/*
**	Functions
*/

void	ft_ssl_parse_args(const int ac, const char **av);

#endif
