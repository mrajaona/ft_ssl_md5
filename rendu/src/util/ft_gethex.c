/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:35:19 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:35:24 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_gethex(const unsigned int i)
{
	if (i < 10)
		return (i + '0');
	else if (i <= 16)
		return (i - 10 + 'a');
	else
		return (0);
}
