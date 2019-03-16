/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:44:10 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/21 14:58:58 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	count_size(int start, char const *str, char c)
{
	int		i;

	i = 0;
	while (str[start] != c && str[start] != '\0')
	{
		start++;
		i++;
	}
	return (i);
}

static char	*ft_cpy_range(char *dst, char const *src, int n, int start)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	define_start(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

t_list		*ft_strsplit_lst(char const *s, char c)
{
	int		i;
	t_list	*first;
	t_list	*curr;

	if (s == NULL)
		return (NULL);
	i = define_start((char *)s, c);
	first = ft_lstnew("", count_size(i, s, c));
	ft_cpy_range(first->content, s, count_size(i, s, c), i);
	curr = first;
	s += i;
	i = 0;
	while (s[i] != '\0')
	{
		if (i != 0 && (s[i] != c && s[i - 1] == c))
		{
			curr->next = ft_lstnew("", count_size(i, s, c));
			ft_cpy_range(curr->next->content, s, count_size(i, s, c), i);
			curr = curr->next;
		}
		i++;
	}
	return (first);
}
