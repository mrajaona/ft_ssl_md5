/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:16:22 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:16:23 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

void	ft_print(const char *str, t_bool endline)
{
	if (str != NULL)
		write(STDOUT, str, ft_strlen(str));
	else
		write(STDOUT, NULLSTR, ft_strlen(NULLSTR));
	if (endline == TRUE)
		write(STDOUT, "\n", 1);
}

void	cpy_err(const char *exe, const char *arg, const char *str, char *msg)
{
	size_t	len;

	len = 0;
	if (exe != NULL)
	{
		ft_strcpy(exe, msg + len);
		len += ft_strlen(exe);
		ft_strcpy(": ", msg + len);
		len += 2;
	}
	if (arg != NULL)
	{
		ft_strcpy(arg, msg + len);
		len += ft_strlen(arg);
		ft_strcpy(": ", msg + len);
		len += 2;
	}
	if (str != NULL)
	{
		ft_strcpy(str, msg + len);
		len += ft_strlen(str);
	}
}

char	*concat_err(const char *exe, const char *arg, const char *str)
{
	size_t	len;
	char	*msg;

	len = 2;
	if (exe != NULL)
		len += ft_strlen(exe) + 2;
	if (arg != NULL)
		len += ft_strlen(arg) + 2;
	if (str != NULL)
		len += ft_strlen(str);
	if ((msg = ft_memalloc(len)) == NULL)
		return (NULL);
	msg[len - 2] = '\n';
	cpy_err(exe, arg, str, msg);
	return (msg);
}

void	ft_printerr(const char *exe, const char *arg, const char *str)
{
	char	*msg;

	msg = concat_err(exe, arg, str);
	if (msg != NULL)
	{
		write(STDERR, msg, ft_strlen(msg));
		ft_strdel(&msg);
	}
}
