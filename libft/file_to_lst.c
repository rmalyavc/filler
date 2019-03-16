/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:29:51 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/03/27 17:25:54 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_list		*file_to_lst(int fd)
{
	t_list	*lst;
	char	*cont;

	cont = NULL;
	lst = NULL;
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &cont) > 0 && cont != NULL)
	{
		ft_lstpush(&lst, ft_lstnew(cont, ft_strlen(cont)));
		ft_strdel(&cont);
	}
	close(fd);
	return (lst);
}
