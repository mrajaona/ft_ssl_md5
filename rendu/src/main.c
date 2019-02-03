#include "parser.h"
#include "input.h"
#include "output.h"

static void init_params(t_params *params, t_cmd *cmd)
{
	params->pos = -1;
	params->stdin = FALSE;
	params->opt_p = FALSE;
	params->opt_q = FALSE;
	params->opt_r = FALSE;
	params->opt_s = FALSE;
	cmd->name = NULL;
	cmd->fn = NULL;
}


static void	ft_checksum(char *file, char *src, t_params *params, t_cmd *cmd)
{
	char		*checksum;

	checksum = cmd->fn(src);
	ft_print_hash(checksum, file == NULL ? src : file, params, cmd);
	ft_strdel(&checksum);
	if (params->stdin == TRUE || params->opt_s == FALSE)
		ft_strdel(&src);
}

static void ft_get_checksums(const int ac, char **av,
	t_params *params, t_cmd *cmd)
{
	char		*src;

	if (params->pos == ac && params->opt_s == TRUE)
	{
		ft_printerr(ERR_OPT_S);
		return ;
	}
	if (params->pos == ac || params->stdin == TRUE)
	{
		src = ft_read_stdin();
		ft_checksum(NULL, src, params, cmd);
		params->stdin = FALSE;
	}
	while (params->pos < ac)
	{
		src = params->opt_s == TRUE
			? av[params->pos] : ft_read_file(av[params->pos]);
        ft_checksum(av[params->pos], src, params, cmd);
        params->opt_s = FALSE;
		params->pos++;
	}
}

int	main(int ac, char **av) {
	t_params	params;
	t_cmd		cmd;

	if (ac == 1)
	{
		ft_print(USAGE, TRUE);
		return (0);
	}
	init_params(&params, &cmd);
	ft_ssl_parse((const int)ac, (const char **)av, &params, &cmd);
	ft_get_checksums((const int)ac, av, &params, &cmd);
	return (0);
}
