#include "output.h"

void	ft_print(const char *str)
{
	if (str != NULL)
		write(STDOUT, str, ft_strlen(str));
	else
		write(STDOUT, NULLSTR, ft_strlen(NULLSTR));
	write(STDOUT, "\n", 1);

}

void	ft_printerr(const char *str)
{
	if (str != NULL)
		write(STDERR, str, ft_strlen(str));
	else
		write(STDERR, NULLSTR, ft_strlen(NULLSTR));
	write(STDERR, "\n", 1);

}

void	ft_print_checksum(const char *checksum, t_params *params)
{
	(void)params;
	if (checksum == NULL)
		return ;
	ft_print(checksum);
}