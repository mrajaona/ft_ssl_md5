#include "ft_ssl.h"

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
	int i;
	unsigned int j;

	i = 2;
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (OPT(av[i][j]))
				set_opt(av[i][j], params);
			else
			{
				ft_printerr(ERR_FLAG);
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

static bool check_cmd(const char *arg, t_params *params)
{
	char *algo_list[N_ALGO];
	unsigned int i = 0;

	algo_list[0] = MD5;
	algo_list[1] = SHA256;
	while (i < N_ALGO)
	{
		if (ft_strcmp(arg, algo_list[i]) == 0)
		{
			params->algo = algo_list[i];
			return (TRUE) ;
		}
		i++;
	}
	ft_printerr(ERR_CMD);
	return (FALSE);
}

static void init_params(t_params *params)
{
	params->algo = NULL;
	params->opt_p = FALSE;
	params->opt_q = FALSE;
	params->opt_r = FALSE;
	params->opt_s = FALSE;
}

void ft_ssl_parse_args(const int ac, const char **av)
{
	t_params	params;
	init_params(&params);

	if (check_cmd(av[1], &params) == FALSE)
		return ;
	if (check_opts(ac, av, &params) == FALSE)
		return ;
}
