/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:26:28 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/17 13:10:28 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s_ptr;
	char		*d_ptr;
	size_t		i;

	i = 0;
	s_ptr = src;
	d_ptr = dst;
	if (dst > src)
		while (len > 0)
		{
			len--;
			d_ptr[len] = s_ptr[len];
		}
	else
		while (i < len)
		{
			d_ptr[i] = s_ptr[i];
			i++;
		}
	return (dst);
}
