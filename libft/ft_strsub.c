/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:10:22 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/19 22:25:04 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * len + 1);
	if (buffer == NULL || s == NULL)
		return (NULL);
	ft_strclr(buffer);
	while (s[start] != '\0' && i < len)
	{
		buffer[i] = s[start];
		i++;
		start++;
	}
	return (buffer);
}
