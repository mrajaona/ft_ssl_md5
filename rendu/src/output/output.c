#include "output.h"

void	ft_print(const char *str, bool endline)
{
	if (str != NULL)
		write(STDOUT, str, ft_strlen(str));
	else
		write(STDOUT, NULLSTR, ft_strlen(NULLSTR));
	if (endline == TRUE)
		write(STDOUT, "\n", 1);
}

void	ft_printerr(const char *str)
{
	if (str != NULL)
		write(STDERR, str, ft_strlen(str));
	else
		write(STDERR, NULLSTR, ft_strlen(NULLSTR));
	write(STDERR, "\n", 1);

}

static void init_cmd_name_list(const char **list)
{
	list[N_MD5] = MD5_MAJ;
	list[N_SHA256] = SHA256_MAJ;
}

void	ft_print_checksum(const char *hash, const char *src, t_params *params)
{
	const char	*list[N_CMDS];
	const char	*cmd;

	if (hash == NULL || src == NULL || params == NULL)
		return ;
	init_cmd_name_list(list);
	cmd = list[params->algo];
	if (params->opt_p == TRUE)
	{
		ft_print(src, TRUE);
		ft_print(hash, TRUE);
		params->stdin = FALSE;
		params->opt_p = FALSE;
		return ;
	}
	else if (params->opt_q == TRUE)
		ft_print(hash, TRUE);
	else if (params->opt_r == TRUE)
	{
		ft_print(hash, FALSE);
		ft_print(params->stdin == FALSE
			&& params->opt_s == TRUE ? " \"" : " ", FALSE);
		if  (params->stdin == FALSE && params->opt_s == TRUE)
		{
			ft_print(src, FALSE);
			ft_print("\"", TRUE);
		}
		else
			ft_print(src, TRUE);
	}
	else
	{
		ft_print(cmd, FALSE);
		ft_print(params->stdin == FALSE
			&& params->opt_s == TRUE ? " (\"" : " (", FALSE);
		ft_print(src, FALSE);
		ft_print(params->stdin == FALSE
			&& params->opt_s == TRUE ? "\") = " : ") = ", FALSE);
		ft_print(hash, TRUE);
	}
	params->opt_s = FALSE;
}
