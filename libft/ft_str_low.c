/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_low.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:42:10 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/19 11:53:32 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_low(char *str)
{
	int		i;

	i = -1;
	if (str == NULL)
		return (NULL);
	while (str[++i] != '\0')
		str[i] = ft_tolower(str[i]);
	return (str);
}
