char	ft_gethex(const unsigned int i)
{
	if (i < 10)
		return (i + '0');
	else if (i <= 16)
		return (i - 10 + 'a');
	else
		return (0);
}