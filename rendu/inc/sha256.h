#ifndef SHA256_H
# define SHA256_H

# include "ft_ssl.h"
# include "input.h"
# include "util.h"

typedef struct			s_sha256
{
	size_t				len;
	char				*src;
	size_t				n_chunks;
	unsigned int		hash[8];
}						t_sha256;

typedef struct			s_calc_sha256
{
	char				*chunk;
	unsigned int		msg_schedule[64];
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		e;
	unsigned int		f;
	unsigned int		g;
	unsigned int		h;
}						t_calc_sha256;

/*
**	Functions
*/

char	*ft_sha256(const char *src, size_t size);
void	sha256_init(t_sha256 *context, const char *src, size_t size);
void	sha256_init_calc(t_calc_sha256 *calc, unsigned int hash[8]);
void	sha256_calc_loop(t_calc_sha256 *calc);
char	*sha256_tostr(unsigned int hash[8]);

#endif
