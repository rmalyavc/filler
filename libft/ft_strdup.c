/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:22:20 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/29 14:05:51 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (buffer == NULL)
		return (NULL);
	buffer = ft_strcpy(buffer, (char *)s1);
	return (buffer);
}
