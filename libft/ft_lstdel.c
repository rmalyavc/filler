/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:23:54 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/15 11:02:45 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr;
	t_list	*prev;

	if (alst == NULL || del == NULL)
		return ;
	prev = *alst;
	curr = prev->next;
	while (prev != NULL)
	{
		del(prev->content, prev->content_size);
		free(prev);
		prev = curr;
		if (curr != NULL)
			curr = curr->next;
	}
	*alst = NULL;
}
