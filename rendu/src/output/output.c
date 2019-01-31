#include "output.h"

void	ft_print(const char *str, bool endline)
{
	if (str != NULL)
		write(STDOUT, str, ft_strlen(str));
	else
		write(STDOUT, NULLSTR, ft_strlen(NULLSTR));
	if (endline == TRUE)
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

void	ft_print_console(const char *hash, const char *src, t_params *params)
{
	if (params->opt_p == TRUE)
	{
		ft_print(src, TRUE);
		return ;
	}
	ft_print(hash, TRUE);
	params->opt_p = FALSE;
}

void	ft_print_checksum(const char *hash, const char *src, t_params *params)
{
	(void)params; (void)src;
	if (hash == NULL)
		return ;
	if (params->opt_q == TRUE)
	{
		ft_print(hash, TRUE);
		return ;
	}
	if (params->opt_s == TRUE)
		params->opt_s = FALSE;
	ft_print("debug", TRUE);
}