#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"
# include <stdlib.h>

enum e_endian
{
	big,
	little
};

/*
** split in 512-bit blocks words
*/
typedef struct			s_block
{
	unsigned long[16]	block;
	struct s_word		*next;
}						t_block;

typedef struct			s_md5
{
	e_endian			endian;
	t_block				*blocks;
	unsigned long		hash[4];
	char				str[33]; // 32 + '\0'
}						t_md5;

/*
**	Functions
*/

char	*ft_md5(const char *src);

#endif
