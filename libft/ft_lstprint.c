/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:49:18 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/03/30 20:26:59 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->content != NULL)
			ft_printf("{green}%s{eoc}\n", lst->content);
		lst = lst->next;
	}
}
