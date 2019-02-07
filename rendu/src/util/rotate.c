/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:37:01 by mrajaona          #+#    #+#             */
/*   Updated: 2019/02/07 10:37:02 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	right_rot(unsigned int word, unsigned int amount)
{
	unsigned int a;
	unsigned int b;

	a = word >> amount;
	b = word << (32 - amount);
	return (a | b);
}

unsigned int	left_rot(unsigned int word, unsigned int amount)
{
	unsigned int a;
	unsigned int b;

	a = word << amount;
	b = word >> (32 - amount);
	return (a | b);
}
