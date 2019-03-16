/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:23:18 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/03/13 19:14:30 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*curr;

	if (alst == NULL && new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		curr = *alst;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
}
