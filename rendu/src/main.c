#include "ft_ssl.h"

int	main(int ac, char **av) {
	if (ac == 1)
	{
		ft_usage();
		return (0);
	}
	ft_ssl_parse_args((const int)ac, (const char **)av);
	return (0);
}