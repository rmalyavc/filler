/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:40:47 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/06 14:53:00 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_buff_cpy(char **buffer)
{
	int		i;
	size_t	size;
	char	**copy;

	i = -1;
	if (buffer == NULL)
		return (NULL);
	size = ft_count_strings(buffer);
	copy = (char **)malloc(sizeof(char *) * size + 1);
	while (++i < (int)size)
	{
		if (!(copy[i] = ft_strdup((const char *)buffer[i])))
		{
			ft_clean_buff(copy, &copy);
			return (NULL);
		}
	}
	copy[i] = 0;
	return (copy);
}
