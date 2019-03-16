/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:05:51 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/16 12:26:42 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char const	*c_ptr;

	i = 0;
	c_ptr = s;
	while (i++ < n)
	{
		if ((unsigned char)c_ptr[0] == (unsigned char)c)
			return ((void *)c_ptr);
		c_ptr += 1;
	}
	return (NULL);
}
