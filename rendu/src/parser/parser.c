#include "parser.h"

static void set_opt(const char opt, t_params *params)
{
	if (opt == 'p')
		params->opt_p = TRUE;
	else if (opt == 'q')
		params->opt_q = TRUE;
	else if (opt == 'r')
		params->opt_r = TRUE;
	else if (opt == 's')
		params->opt_s = TRUE;
}

static bool check_opts(const int ac, const char **av, t_params *params)
{
	unsigned int j;

	params->pos = 2;
	while (params->pos < ac && av[params->pos][0] == '-')
	{
		j = 1;
		while (av[params->pos][j])
		{
			if (OPT(av[params->pos][j]))
				set_opt(av[params->pos][j], params);
			else
			{
				ft_printerr(ERR_FLAG);
				return (FALSE);
			}
			j++;
		}
		params->pos++;
	}
	return (TRUE);
}

static void init_cmd_name_list(const char **list)
{
	list[N_MD5] = MD5;
	list[N_SHA256] = SHA256;
}

static bool check_cmd(const char *arg, t_params *params)
{
	const char		*list[N_CMDS];
	unsigned int	i = 0;

	init_cmd_name_list(list);
	while (i < N_CMDS)
	{
		if (ft_strcmp(arg, list[i]) == 0)
		{
			params->algo = i;
			return (TRUE) ;
		}
		i++;
	}
	ft_printerr(ERR_CMD);
	return (FALSE);
}

static void init_params(t_params *params)
{
	params->algo = -1;
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

void ft_ssl_parse_args(const int ac, const char **av)
{
	t_params	params;
	char		*(*list[N_CMDS])(t_params *, const char *);
	char		*checksum;

	init_params(&params);
	init_cmd_list(list);
	if (check_cmd(av[1], &params) == FALSE
		|| check_opts(ac, av, &params) == FALSE
		|| params.algo < 0
		|| params.algo >= N_CMDS)
		return ;
	while (params.pos < ac)
	{
		checksum = list[params.algo](&params, av[params.pos]);
		ft_print_checksum(checksum, &params);
		params.pos++;
	}
}
