/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:54:31 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/15 11:58:51 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)(ft_strlen((char *)s));
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen((char *)s)));
	while (--i >= 0)
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (NULL);
}
