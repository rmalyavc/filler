/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:24:45 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/02/27 21:46:53 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isnum(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] != '\0')
		if (ft_isdigit(str[i]) == 0 &&
				((str[i] != '-' && str[i] != '+') || i != 0))
			return (0);
	if (ft_isdigit(str[0]) == 0 && ft_strlen(str) == 1)
		return (0);
	return (1);
}
