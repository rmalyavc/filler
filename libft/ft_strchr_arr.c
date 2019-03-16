/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 21:34:42 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/16 21:38:47 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strchr_arr(char *haystack, char *needles)
{
	int		i;

	i = -1;
	while (needles[++i])
		if (ft_strchr(haystack, needles[i]))
			return (1);
	return (0);
}
