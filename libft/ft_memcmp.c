/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:52:03 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/16 12:49:43 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1_ptr;
	const char	*s2_ptr;

	i = 0;
	s1_ptr = s1;
	s2_ptr = s2;
	while (i < n)
	{
		if ((unsigned char)s1_ptr[i] != (unsigned char)s2_ptr[i])
			return ((unsigned char)s1_ptr[i] - (unsigned char)s2_ptr[i]);
		i++;
	}
	if (i == 0)
		return (0);
	return ((unsigned char)s1_ptr[i - 1] - (unsigned char)s2_ptr[i - 1]);
}
