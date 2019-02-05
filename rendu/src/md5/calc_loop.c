#include "md5.h"

void	calc_loop(t_calc	*calc)
{
	unsigned int	tmp;
	size_t	j;

	j = 0;
	while (j < 64)
	{
		if (j < 16)
			tmp = ft_round_f(calc, j);
		else if (j < 32)
			tmp = ft_round_g(calc, j);
		else if (j < 48)
			tmp = ft_round_h(calc, j);
		else
			tmp = ft_round_i(calc, j);
		calc->a = calc->d;
		calc->d = calc->c;
		calc->c = calc->b;
		calc->b = tmp;
		j++;
	}
}