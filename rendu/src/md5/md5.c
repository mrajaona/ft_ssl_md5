#include "md5.h"

/*
** creates a 128 bits hash
** empty hash : d41d8cd98f00b204e9800998ecf8427e
**
** check <limits.h> CHAR_BIT for byte size
** check little/big endian
*/

static unsigned long	F(unsigned long B, unsigned long C, unsigned long D)
{
	return ((B & C) | (~B & D));
}
static unsigned long	G(unsigned long B, unsigned long C, unsigned long D)
{
	return ((B & D) | (C & ~D));
}
static unsigned long	H(unsigned long B, unsigned long C, unsigned long D)
{
	return (B ^ C ^ D);
}
static unsigned long	I(unsigned long B, unsigned long C, unsigned long D)
{
	return (C ^ (B | ~D));
}

static t_block		*ft_new(unsigned long *data)
{
	t_block	*new_elem;

	if ((new_elem = malloc(sizeof(t_block))) == NULL)
		return (NULL);
	new_elem->next = NULL;
	new_elem->block = data;
	return (new_elem);
}

static void	init_blocks(t_block **list, const char *src)
{
	const char		*tmp;
	unsigned int	i;
	size_t			len;
	char			buf[64];

	tmp = src;
	len = 0;
	while (*tmp)
	{
		i = 0;
		while (i < 64 && *tmp)
		{
			buf[i] = *tmp;
			i++;
			tmp++;
		}

		// TODO : Padding

	}
}

static e_endian check_endian( void )
{
   unsigned int	i;
   char			*c;

   i = 1;
   c = (char *)&i
   return (*c ? little : big);
}

char	*ft_md5(const char *src)
{
	t_md5	context;

    context.endian = check_endian();
    context.hash[0] = 0x67452301;
    context.hash[1] = 0xefcdab89;
    context.hash[2] = 0x98badcfe;
    context.hash[3] = 0x10325476;
    context.blocks = NULL;
    init_blocks(&(context.blocks), src);

	return ("md5 !");
}

