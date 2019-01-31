#ifndef FT_SSL_H
# define FT_SSL_H

# include "output.h"

# define TRUE 1
# define FALSE 0

# define OK 0
# define ERR 1

# define N_ALGO 2
# define MD5 "md5"
# define SHA256 "sha256"

# define OPT(opt) opt == 'p' || opt == 'q' || opt == 'r' || opt == 's'

typedef int		bool;
typedef char	byte;

typedef struct	s_params
{
	char		*algo;
	bool		opt_p;
	bool		opt_q;
	bool		opt_r;
	bool		opt_s;
}				t_params;

/*
**	Functions
*/

void ft_ssl_parse_args(const int ac, const char **av);

#endif
