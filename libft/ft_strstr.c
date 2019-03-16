/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:12:26 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/19 22:34:23 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[0] != '\0')
	{
		if (ft_strncmp(haystack, needle, ft_strlen((char *)needle)) == 0)
			return ((char *)haystack);
		haystack += 1;
	}
	return (NULL);
}
