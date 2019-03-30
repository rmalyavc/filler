/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:32:05 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/30 17:28:13 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_list	*map_list(t_list *lst, int size)
{
	char		*line;
	char		*ptr;

	line = NULL;
	while (size-- >= 0)
	{
		if (get_next_line(0, &line) < 1 || !line)
			return (NULL);
		if (ft_strchr_arr(line, ".OoXx"))
		{
			ptr = ft_strchr(line, ' ') + 1;
			ft_lstpush(&lst, ft_lstnew(ptr, ft_strlen(ptr)));
			ft_strdel(&line);
		}
	}
	return (lst);
}

static t_list	*piece_list(t_list *lst, int size)
{
	char		*line;

	line = NULL;
	while (size-- > 0)
	{
		if (get_next_line(0, &line) < 1 || !line || !ft_strchr_arr(line, ".*"))
			return (NULL);
		ft_lstpush(&lst, ft_lstnew(line, ft_strlen(line)));
		ft_strdel(&line);
	}
	return (lst);
}

static int		read_map(t_map **data, t_list *(*get_list)(t_list *, int))
{
	char		*str;
	char		**parsed;
	int			res;
	t_list		*lst;

	res = get_next_line(0, &str);
	if (res < 1 || !(parsed = ft_strsplit(str, ' ')) ||
		(ft_count_strings(parsed) < 3 && ft_clean_buff(parsed, &parsed)))
		return (0);
	(*data)->rows = ft_atoi(parsed[1]);
	(*data)->cols = ft_atoi(parsed[2]);
	if (ft_clean_buff(parsed, &parsed) &&
		!(lst = get_list(NULL, (*data)->rows)))
		return (0);
	if (!((*data)->map = ft_lst_to_buff(&lst, 1)))
		return (0);
	return (1);
}

int				get_data(t_filler *data)
{
	return (read_map(&(data->map), &map_list) &&
			read_map(&(data->piece), &piece_list));
}
