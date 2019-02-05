#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"
# include "output.h"
# include "util.h"
# include <stdlib.h>

enum	e_endian
{
	big,
	little
};

typedef struct			s_md5
{
	size_t				len;
	char				*src;
	size_t				n_chunks;
	unsigned int		hash[4];
}						t_md5;

typedef struct			s_calc
{
	char				*chunk;
	unsigned int		word;
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
}						t_calc;

/*
**	Functions
*/

char            *ft_md5(const char *src, size_t size);
void	        md5init(t_md5 *context, const char *src, size_t size);
void            calc_loop(t_calc	*calc);
unsigned int	ft_round_f(t_calc *calc, unsigned int j);
unsigned int	ft_round_g(t_calc *calc, unsigned int j);
unsigned int	ft_round_h(t_calc *calc, unsigned int j);
unsigned int	ft_round_i(t_calc *calc, unsigned int j);
char	        *tostr(unsigned int hash[4]);
#endif
