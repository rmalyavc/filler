/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:36:51 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/03/02 13:15:49 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->next = NULL;
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
		return (elem);
	}
	if (content_size > 0)
	{
		elem->content = ft_strnew(content_size);
		if (elem->content != NULL)
			ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	return (elem);
}
