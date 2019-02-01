#ifndef FT_SSL_H
# define FT_SSL_H

typedef char	byte;

# define TRUE 1
# define FALSE 0

# define N_CMDS 2
# define MD5 "md5"
# define MD5_MAJ "MD5"
# define N_MD5 0
# define SHA256 "sha256"
# define SHA256_MAJ "SHA256"
# define N_SHA256 1

typedef int		bool;

typedef struct	s_params
{
	int			pos;
	int			algo;
	bool		stdin;
	bool		opt_p;
	bool		opt_q;
	bool		opt_r;
	bool		opt_s;
}				t_params;

#endif
