/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:37:30 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/12 15:40:30 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_strlen(dst) - 1;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	if (ft_strlen(dst) > dstsize)
		len = dstsize - 1;
	else
		len = i;
	while (++i < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
	}
	dst[i] = '\0';
	return (len + ft_strlen((char *)src) + 1);
}
