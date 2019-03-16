/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:42:16 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/06 14:52:23 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_create_buff(size_t size, size_t len)
{
	size_t	i;
	char	**buffer;

	i = 0;
	if (!(buffer = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	buffer[size] = 0;
	while (i < size)
	{
		if (!(buffer[i] = ft_strnew(len + 1)))
		{
			ft_clean_buff(buffer, &buffer);
			return (NULL);
		}
		ft_memset(buffer[i], '\0', len + 1);
		i++;
	}
	return (buffer);
}
