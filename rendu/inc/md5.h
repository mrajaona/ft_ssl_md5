#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"
# include "util.h"
# include <stdlib.h>

enum	e_endian
{
	big,
	little
};

typedef struct			s_md5
{
	enum e_endian		endian;
	size_t				len;
	char				*src;
	unsigned int		n_chunks;
	unsigned long		hash[4];
}						t_md5;

/*
**	Functions
*/

char	*ft_md5(const char *src);

#endif
