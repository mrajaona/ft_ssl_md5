/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:16:32 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:16:33 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

static void	print_opt_p(const char *hash, const char *src, t_params *params)
{
	ft_print(src, FALSE);
	ft_print(hash, TRUE);
	params->std_in = FALSE;
	params->opt_p = FALSE;
}

static void	print_opt_r(const char *hash, const char *src, t_params *params)
{
	ft_print(hash, FALSE);
	ft_print(params->std_in == FALSE
		&& params->opt_s == TRUE ? " \"" : " ", FALSE);
	if (params->std_in == FALSE && params->opt_s == TRUE)
	{
		ft_print(src, FALSE);
		ft_print("\"", TRUE);
	}
	else
		ft_print(src, TRUE);
}

static void	print_no_opt(const char *hash, const char *src, t_params *params)
{
	ft_print((const char *)params->cmd.name, FALSE);
	ft_print(params->std_in == FALSE
		&& params->opt_s == TRUE ? "(\"" : "(", FALSE);
	ft_print(src, FALSE);
	ft_print(params->std_in == FALSE
		&& params->opt_s == TRUE ? "\")= " : ")= ", FALSE);
	ft_print(hash, TRUE);
}

void		ft_print_hash(const char *hash, const char *src, t_params *params)
{
	if (hash == NULL || src == NULL || params == NULL)
		return ;
	if (params->opt_p == TRUE)
	{
		print_opt_p(hash, src, params);
		return ;
	}
	else if (params->opt_q == TRUE)
		ft_print(hash, TRUE);
	else if (params->opt_r == TRUE)
		print_opt_r(hash, src, params);
	else
		print_no_opt(hash, src, params);
}
