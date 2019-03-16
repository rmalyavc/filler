/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:36:09 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/15 11:17:59 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (c > 0 && (ft_isdigit(c) != 0 || ft_isalpha(c) != 0))
		return (1);
	return (0);
}