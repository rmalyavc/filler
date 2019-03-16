/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:39 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/15 11:05:02 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*first;
	t_list	*curr;

	if (lst == NULL || f == NULL)
		return (NULL);
	first = f(lst);
	curr = first;
	while (lst->next != NULL)
	{
		curr->next = f(lst->next);
		curr = curr->next;
		lst = lst->next;
	}
	return (first);
}
