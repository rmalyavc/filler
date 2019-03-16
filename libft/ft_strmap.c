/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:51:31 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/17 00:01:39 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		buffer[i] = f(s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
