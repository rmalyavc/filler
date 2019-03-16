/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:13:36 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/02 19:26:02 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_count_strings(char **buffer)
{
	size_t	i;

	i = 0;
	if (buffer != NULL)
		while (buffer[i])
			i++;
	return (i);
}
