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

static void print_opt_p(const char *hash, const char *src, t_params *params)
{
	ft_print(src, TRUE);
	ft_print(hash, TRUE);
	params->stdin = FALSE;
	params->opt_p = FALSE;
}

static void print_opt_r(const char *hash, const char *src, t_params *params)
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

static void print_no_opt(const char *hash, const char *src,
	t_params *params, t_cmd *cmd)
{
	ft_print((const char *)cmd->name, FALSE);
	ft_print(params->stdin == FALSE
		&& params->opt_s == TRUE ? "(\"" : "(", FALSE);
	ft_print(src, FALSE);
	ft_print(params->stdin == FALSE
		&& params->opt_s == TRUE ? "\")= " : ")= ", FALSE);
	ft_print(hash, TRUE);
}

void	ft_print_hash(const char *hash, const char *src,
	t_params *params, t_cmd *cmd)
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
		print_no_opt(hash, src, params, cmd);
}
