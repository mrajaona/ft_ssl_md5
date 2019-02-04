#include "parser.h"
#include "input.h"
#include "output.h"

static void init_params(t_params *params)
{
	params->pos = -1;
	params->stdin = FALSE;
	params->opt_p = FALSE;
	params->opt_q = FALSE;
	params->opt_r = FALSE;
	params->opt_s = FALSE;
	params->cmd.name = NULL;
	params->cmd.fn = NULL;
	params->file_size = 0;
}


static void	ft_checksum(char *file, char *src, t_params *params)
{
	char		*checksum;

	if (src == NULL)
	{
		ft_printerr("Error: no source.");
		return ;
	}
	checksum = params->cmd.fn(src, params->file_size);
	ft_print_hash(checksum, file == NULL ? src : file, params);
	ft_strdel(&checksum);
	if (params->stdin == TRUE || params->opt_s == FALSE)
	{
		ft_strdel(&src);
		params->file_size = 0;
	}
}

static void ft_get_checksums(const int ac, char **av, t_params *params)
{
	char		*src;

	if (params->pos == ac && params->opt_s == TRUE)
	{
		ft_printerr(ERR_OPT_S);
		return ;
	}
	if (params->pos == ac || params->stdin == TRUE)
	{
		src = ft_read_stdin(&(params->file_size));
		ft_checksum(NULL, src, params);
		params->stdin = FALSE;
	}
	while (params->pos < ac)
	{
		src = params->opt_s == TRUE ? av[params->pos]
			: ft_read_file(av[params->pos], &(params->file_size));
        ft_checksum(av[params->pos], src, params);
        params->opt_s = FALSE;
		params->pos++;
	}
}

int	main(int ac, char **av) {
	t_params	params;

	if (ac == 1)
	{
		ft_print(USAGE, TRUE);
		return (0);
	}
	init_params(&params);
	ft_ssl_parse((const int)ac, (const char **)av, &params);
	ft_get_checksums((const int)ac, av, &params);
	return (0);
}
