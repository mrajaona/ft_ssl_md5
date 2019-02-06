#include "parser.h"
#include "input.h"
#include "output.h"

static void init_params(t_params *params, char *exe)
{
	params->exe = exe;
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
		return ;
	checksum = params->cmd.fn(src, params->file_size);
	ft_print_hash(checksum, file == NULL ? src : file, params);
	ft_strdel(&checksum);
	if (params->stdin == TRUE || params->opt_s == FALSE)
	{
		ft_strdel(&src);
		params->file_size = 0;
	}
}

static bool ft_get_checksums(const int ac, char **av, t_params *params)
{
	char		*src;

	if (params->pos == ac && params->opt_s == TRUE)
	{
		ft_printerr(params->exe, NULL, ERR_OPT_S);
		return (FALSE);
	}
	if (params->pos == ac || params->stdin == TRUE)
	{
		src = ft_read_stdin(params);
		ft_checksum(NULL, src, params);
		params->stdin = FALSE;
	}
	while (params->pos < ac)
	{
		src = params->opt_s == TRUE ? av[params->pos]
			: ft_read_file(av[params->pos], params);
        ft_checksum(av[params->pos], src, params);
        params->opt_s = FALSE;
		params->pos++;
	}
	return (TRUE);
}

int	main(int ac, char **av) {
	t_params	params;

	if (ac == 1)
	{
		ft_print(USAGE, TRUE);
		return (0);
	}
	init_params(&params, av[0]);
	if (ft_ssl_parse((const int)ac, (const char **)av, &params) == FALSE)
		return (1);
	if (ft_get_checksums((const int)ac, av, &params) == FALSE)
		return (1);
	return (0);
}
