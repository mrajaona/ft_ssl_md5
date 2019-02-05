#include "util.h"

unsigned int	ft_endian_uint(unsigned int src)
{
	unsigned int	masked[4];

	masked[0] = (src & 0x000000ff) << 24u;
	masked[1] = (src & 0x0000ff00) << 8u;
	masked[2] = (src & 0x00ff0000) >> 8u;
	masked[3] = (src & 0xff000000) >> 24u;

	return (masked[0] | masked[1] | masked[2] | masked[3]);
}

size_t			ft_endian_size_t(size_t src)
{
	size_t	masked[8];

	masked[0] = (src & 0x00000000000000ff) << 48u;
	masked[1] = (src & 0x000000000000ff00) << 40u;
	masked[2] = (src & 0x0000000000ff0000) << 24u;
	masked[3] = (src & 0x00000000ff000000) << 8u;

	masked[4] = (src & 0x000000ff00000000) >> 8u;
	masked[5] = (src & 0x0000ff0000000000) >> 24u;
	masked[6] = (src & 0x00ff000000000000) >> 40u;
	masked[7] = (src & 0xff00000000000000) >> 48u;

	return (masked[0] | masked[1] | masked[2] | masked[3]
		| masked[4] | masked[5] | masked[6] | masked[7]);
}