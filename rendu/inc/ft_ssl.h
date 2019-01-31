#ifndef FT_SSL_H
# define FT_SSL_H

typedef char	byte;

# define TRUE 1
# define FALSE 0

typedef int		bool;

typedef struct	s_params
{
	int			pos;
	int			algo;
	bool		opt_p;
	bool		opt_q;
	bool		opt_r;
	bool		opt_s;
}				t_params;

#endif
