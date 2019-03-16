/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:58:30 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/20 20:43:57 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_power(int nb, int power)
{
	intmax_t	res;
	int			i;

	i = 0;
	res = nb;
	while (power < 0 && --i > power)
		res /= 10;
	while (power > 0 && ++i < power)
		res *= 10;
	if (power == 0)
		res = 1;
	return (res);
}
