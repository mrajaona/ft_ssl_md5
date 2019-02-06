unsigned int	right_rot(unsigned int word, unsigned int amount)
{
	unsigned int a;
	unsigned int b;

	a = word >> amount;
	b = word << (32 - amount);
	return (a | b);
}

unsigned int	left_rot(unsigned int word, unsigned int amount)
{
	unsigned int a;
	unsigned int b;

	a = word << amount;
	b = word >> (32 - amount);
	return (a | b);
}