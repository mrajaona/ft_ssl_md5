#include "parser.h"

int	main(int ac, char **av) {
	if (ac == 1)
	{
		ft_print(USAGE, TRUE);
		return (0);
	}
	ft_ssl_parse_args((const int)ac, (const char **)av);
	return (0);
}