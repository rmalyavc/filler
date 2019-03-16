/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:54:51 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/19 21:46:14 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*buffer;
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (ptr);
	buffer = ptr;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
	return (ptr);
}
