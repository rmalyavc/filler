/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:37:33 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/03/11 19:48:10 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_clean_buff(char **buffer, char ***ptr)
{
	int		i;

	i = -1;
	if (buffer == NULL || *buffer == NULL)
		return (1);
	while (buffer[++i] != NULL)
		ft_strdel(&buffer[i]);
	free(buffer);
	*ptr = NULL;
	return (1);
}
