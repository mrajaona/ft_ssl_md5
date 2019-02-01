#ifndef FT_SSL_H
# define FT_SSL_H

typedef char	byte;

# define TRUE 1
# define FALSE 0

# define N_CMDS 2
# define MD5 "md5"
# define SHA256 "sha256"

typedef int		bool;

typedef struct	s_params
{
	int			pos;
	bool		stdin;
	bool		opt_p;
	bool		opt_q;
	bool		opt_r;
	bool		opt_s;
}				t_params;

typedef struct	s_cmd
{
	char		*name;
	char		*(*fn)(t_params *, const char *);
}				t_cmd;

#endif
