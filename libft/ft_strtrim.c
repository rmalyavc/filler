/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:58:06 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/17 00:01:37 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*buffer;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen((char *)s);
	if (j > 0)
		j--;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	if (i < j)
		while (s[j] == '\t' || s[j] == ' ' || s[j] == '\n')
			j--;
	buffer = (char *)malloc(sizeof(char) * (j - i + 2));
	if (buffer == NULL)
		return (NULL);
	while (i <= j)
		buffer[k++] = s[i++];
	buffer[k] = '\0';
	return (buffer);
}
