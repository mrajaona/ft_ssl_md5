/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:16:48 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:16:49 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		set_opt(const char opt, t_params *params)
{
	if (opt == 'p')
	{
		params->opt_p = TRUE;
		params->std_in = TRUE;
	}
	else if (opt == 'q')
		params->opt_q = TRUE;
	else if (opt == 'r')
		params->opt_r = TRUE;
	else if (opt == 's')
		params->opt_s = TRUE;
}

static t_bool	check_opts(const int ac, const char **av, t_params *params)
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
				ft_printerr(params->exe, av[params->pos], ERR_FLAG);
				return (FALSE);
			}
			j++;
		}
		params->pos++;
	}
	return (TRUE);
}

static void		init_lists(t_cmd *cmd_list)
{
	cmd_list[0].name = "md5";
	cmd_list[0].fn = ft_md5;
	cmd_list[1].name = "sha256";
	cmd_list[1].fn = ft_sha256;
}

static t_bool	check_cmd(const char **av, t_cmd *cmd)
{
	t_cmd			cmd_list[N_CMDS];
	unsigned int	i;

	init_lists(cmd_list);
	i = 0;
	while (i < N_CMDS)
	{
		if (ft_strcmp(av[1], cmd_list[i].name) == 0)
		{
			cmd->name = cmd_list[i].name;
			cmd->fn = cmd_list[i].fn;
			return (TRUE);
		}
		i++;
	}
	ft_printerr(av[0], av[1], ERR_CMD);
	return (FALSE);
}

t_bool			ft_ssl_parse(const int ac, const char **av, t_params *params)
{
	if (check_cmd(av, &(params->cmd)) == FALSE
		|| check_opts(ac, av, params) == FALSE
		|| params->cmd.name == NULL
		|| params->cmd.fn == NULL)
		return (FALSE);
	return (TRUE);
}
