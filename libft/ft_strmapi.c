/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:53:21 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/16 23:47:20 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buffer;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (buffer == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = f((unsigned int)i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
