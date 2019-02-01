#include "parser.h"
#include "output.h"

static void init_params(t_params *params)
{
	params->pos = -1;
	params->algo = -1;
	params->stdin = FALSE;
	params->opt_p = FALSE;
	params->opt_q = FALSE;
	params->opt_r = FALSE;
	params->opt_s = FALSE;
}

static void init_cmd_list(char *(** list)(t_params *, const char *))
{
	list[N_MD5] = ft_md5;
	list[N_SHA256] = ft_sha256;
}


static char *ft_read_stdin( void )
{
	// TODO
	return ( NULL );
}

static void ft_get_checksums(const int ac, const char **av, t_params *params)
{
	char		*checksum;
	char		*src;
	char		*(*list[N_CMDS])(t_params *, const char *);

	init_cmd_list(list);
	if (params->pos == ac && params->opt_s == TRUE)
	{
		ft_printerr(ERR_OPT_S);
		return ;
	}
	if (params->pos == ac || params->opt_p == TRUE)
	{
		params->stdin = TRUE;
		src = ft_read_stdin();
		checksum = list[params->algo](params, src);
		ft_print_checksum(checksum, src, params);
	}
	while (params->pos < ac)
	{
		checksum = list[params->algo](params, av[params->pos]);
		ft_print_checksum(checksum, av[params->pos], params);
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
	ft_ssl_parse_args((const int)ac, (const char **)av, &params);
	ft_get_checksums((const int)ac, (const char **)av, &params);
	return (0);
}
