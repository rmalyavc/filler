/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:58:16 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/16 13:57:08 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
			break ;
		i++;
	}
	if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
		return (0);
	return (1);
}
