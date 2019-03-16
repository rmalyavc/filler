/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:53:09 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/20 19:28:36 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf	*new_to_lst(t_printf **lst, size_t size)
{
	t_printf	*curr;
	t_printf	*elem;
	int			i;

	i = -1;
	if (lst == NULL || !(elem = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	curr = *lst;
	if (!(elem->flags = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (++i < (int)size + 1)
		elem->flags[i] = NULL;
	elem->next = NULL;
	elem->data = NULL;
	elem->spec = '\0';
	elem->width = 0;
	if (*lst == NULL)
	{
		*lst = elem;
		return (elem);
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = elem;
	return (elem);
}

static t_printf	*fill_elem(t_printf *elem, char *s, char *fl, char *sp)
{
	int		i;
	char	buffer[12];

	i = -1;
	while (s[++i] && (ft_strchr(fl, s[i]) || ft_isdigit(s[i]) == 1))
		if ((ft_memset(buffer, '\0', 12) && ft_strchr(fl, s[i]) != NULL))
		{
			if ((s[i] == 'l' && s[i + 1] == 'l') ||
					(s[i] == 'h' && s[i + 1] == 'h'))
				ft_strncat(buffer, &s[i], 2);
			else if (ft_strchr(buffer, s[i]) == NULL || s[i] == '*')
				ft_strncat(buffer, &s[i], 1);
			if (ft_str_search(elem->flags, buffer) < 0 || s[i] == '*')
				elem->flags[ft_count_strings(elem->flags)] = ft_strdup(buffer);
		}
		else if ((elem->flags[ft_count_strings(elem->flags)] =
					ft_itoa(ft_atoi(&s[i]))))
			i += ft_strlen(elem->flags[ft_count_strings(elem->flags) - 1]) - 1;
	if (s[i] == '%')
		elem->data = ft_strdup("%");
	if ((!ft_strchr(sp, s[i]) || s[i] == '\0') && elem->data == NULL)
		elem->data = ft_strdup("");
	else
		elem->spec = s[i];
	return (elem);
}

static void		tolow_specs(t_printf *lst)
{
	char	c;
	int		pos;

	while (lst != NULL)
	{
		c = lst->spec;
		if (ft_memchr("DSOUCFE", c, 7))
		{
			if ((pos = ft_str_search(lst->flags, "L")) != -1)
				lst->flags[pos][0] = 'l';
			if (ft_str_search(lst->flags, "l") < 0)
				lst->flags[ft_count_strings(lst->flags)] = ft_strdup("l");
			lst->spec = ft_tolower(lst->spec);
		}
		lst = lst->next;
	}
}

t_printf		*make_list(char *src, char *flags, char *specs)
{
	t_printf	*lst;
	t_printf	*curr;

	lst = NULL;
	while (src[0] != '\0')
	{
		if (src[0] == '%')
		{
			if (!(curr = fill_elem(new_to_lst(&lst, 15),
							src + 1, flags, specs)))
				return (NULL);
			else if (curr->data != NULL && ft_strcmp(curr->data, "%") == 0)
				src = ft_strchr(&src[1], '%');
			if (curr->spec == 'p' && (curr->spec = 'x'))
				curr->flags[ft_count_strings(curr->flags)] = ft_strdup("p");
		}
		src++;
	}
	tolow_specs(lst);
	return (lst);
}
