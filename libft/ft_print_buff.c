/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:11:12 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/19 14:11:20 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_buff(char **buffer)
{
	size_t	i;

	i = 0;
	if (buffer == NULL)
		return ;
	while (buffer[i])
	{
		ft_putstr(buffer[i]);
		ft_putstr("\n");
		i++;
	}
}
