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
		if (get_next_line(0, &line) < 1 || !line)
			return (NULL);
		ft_lstpush(&lst, ft_lstnew(line, ft_strlen(line)));
		ft_strdel(&line);
	}
	return (lst);
}

static int		def_last(char **tmp, t_map **data, char enemy)
{
	int			i;
	int			j;

	i = -1;
	if (!tmp || !(*data)->map)
		return (1);
	while (++i < (*data)->rows && (j = -1))
	{
		while (++j < (*data)->cols)
		{
			if (tmp[i][j] == ft_tolower(enemy))
				tmp[i][j] = enemy;
			if (tmp[i][j] != enemy && (*data)->map[i][j] == enemy)
				(*data)->map[i][j] = ft_tolower((*data)->map[i][j]);
		}
	}
	return (1);
}

static int		read_map(t_map **data, t_list *(*get_list)(t_list *, int),
				char enemy)
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
	if (enemy)
		parsed = ft_buff_cpy((*data)->map);
	if (!((*data)->map = ft_lst_to_buff(&lst, 1)))
		return (0);
	if (parsed && def_last(parsed, data, enemy))
		ft_clean_buff(parsed, &parsed);
	return (1);
}

int				get_data(t_filler *data)
{
	int read_map_res;
	int read_piece_res;

	read_map_res = read_map(&(data->map), &map_list, data->enemy);
	read_piece_res = read_map(&(data->piece), &piece_list, 0);
	return (read_map_res && read_piece_res);
}
