/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:18:48 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/08 14:26:47 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * size + 1);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, size + 1);
	return (buffer);
}
