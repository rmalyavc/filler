/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:43:04 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/05 20:33:49 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_search(char **haystack, char *needle)
{
	int		i;

	i = -1;
	if (haystack != NULL && needle != NULL)
		while (haystack[++i])
			if (ft_strcmp(haystack[i], needle) == 0)
				return (i);
	return (-1);
}
