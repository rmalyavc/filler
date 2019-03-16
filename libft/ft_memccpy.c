/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:58:51 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/16 12:25:38 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*d_ptr;
	const char	*s_ptr;
	size_t		i;

	d_ptr = dest;
	s_ptr = src;
	i = -1;
	while (++i < n)
	{
		d_ptr[i] = s_ptr[i];
		if ((unsigned char)s_ptr[i] == (unsigned char)c)
			return (&d_ptr[i + 1]);
	}
	return (NULL);
}
