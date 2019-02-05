unsigned int	ft_switch_endian(unsigned int src)
{
	unsigned int	masked[4];

	masked[0] = (src & 0x000000ff) << 24u;
	masked[1] = (src & 0x0000ff00) << 8u;
	masked[2] = (src & 0x00ff0000) >> 8u;
	masked[3] = (src & 0xff000000) >> 24u;

	return (masked[0] | masked[1] | masked[2] | masked[3]);
}