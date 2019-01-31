#include "ft_ssl.h"

int	main(int ac, char **av) {
	if (ac == 1)
	{
		ft_usage();
		return (OK);
	}
	ft_ssl_parse_args((const int)ac, (const char **)av);
	return (OK);
}