/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:25:49 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/16 23:49:38 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) *
			(ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	if (buffer == NULL)
		return (NULL);
	while (s1[j] != '\0')
		buffer[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		buffer[i++] = s2[j++];
	buffer[i] = '\0';
	return (buffer);
}
