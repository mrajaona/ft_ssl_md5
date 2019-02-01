#include "parser.h"

static void set_opt(const char opt, t_params *params)
{
	if (opt == 'p')
	{
		params->opt_p = TRUE;
		params->stdin = TRUE;
	}
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
			if (av[params->pos][j] == 'p' || av[params->pos][j] == 'q'
				|| av[params->pos][j] == 'r' || av[params->pos][j] == 's')
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

void ft_ssl_parse_args(const int ac, const char **av, t_params *params)
{
	if (check_cmd(av[1], params) == FALSE
		|| check_opts(ac, av, params) == FALSE
		|| params->algo < 0
		|| params->algo >= N_CMDS)
		return ;
}
