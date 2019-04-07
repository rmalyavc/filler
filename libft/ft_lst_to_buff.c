/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:14:53 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/16 21:00:13 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_buff(t_list **lst, int clean)
{
	t_list	*ptr;
	char	**buff;
	int		size;
	int		i;

	if (!lst || !(*lst) || !(size = ft_lstlen(*lst)))
		return (NULL);
	ptr = *lst;
	i = -1;
	if (!(buff = (char **)malloc((sizeof(char *) * size) + 1)))
		return (NULL);
	while (ptr)
	{
		if (!(buff[++i] = ft_strdup(ptr->content)) &&
			ft_clean_buff(buff, &buff))
			return (NULL);
		ptr = ptr->next;
	}
	buff[++i] = NULL;
	if (clean)
		ft_lstclear(lst);
	return (buff);
}
