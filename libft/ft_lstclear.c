/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:57:40 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/03/10 19:20:10 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;
	t_list	*prev;

	if (lst == NULL || *lst == NULL)
		return ;
	prev = *lst;
	while (prev != NULL)
	{
		curr = prev->next;
		if (prev->content != NULL)
			free(prev->content);
		free(prev);
		prev = curr;
	}
	*lst = NULL;
}
