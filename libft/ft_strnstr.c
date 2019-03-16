/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:18:10 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/19 22:24:10 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	size = ft_strlen((char *)needle);
	while (haystack[0] != '\0' && i <= len - size && size <= len)
	{
		if (ft_strncmp(haystack, needle, size) == 0)
			return ((char *)haystack);
		haystack += 1;
		i++;
	}
	return (NULL);
}
