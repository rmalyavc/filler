/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:49:09 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/27 15:51:00 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str_push(char **buffer, char *str)
{
	int		size;
	char	**tmp;
	int		i;

	i = -1;
	if (str == NULL)
		return (buffer);
	else if (buffer == NULL)
	{
		if (!(buffer = ft_strsplit(str, '\0')))
			return (NULL);
	}
	else
	{
		size = ft_count_strings(buffer);
		if (!(tmp = (char **)malloc(sizeof(char *) * size + 2)))
			return (NULL);
		while (++i < size)
			if (!(tmp[i] = ft_strdup(buffer[i])))
				return (NULL);
		tmp[size] = ft_strdup(str);
		ft_clean_buff(buffer, &buffer);
		buffer = tmp;
	}
	return (buffer);
}
