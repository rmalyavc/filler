/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:00:40 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/30 17:07:37 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <time.h>

static int		need_offset_x(char **piece, int size)
{
	while (--size >= 0)
		if (piece[size][0] == '*')
			return (0);
	return (1);
}

static char		**cut_spare(char **piece, int size, int *off_x, int *off_y)
{
	int			i;

	i = -1;
	while (++i < size && !ft_strchr(piece[i - *off_y], '*'))
	{
		piece += 1;
		*off_y += 1;
	}
	while (need_offset_x(piece, (int)ft_count_strings(piece)) && (i = -1))
	{
		while (++i < (int)ft_count_strings(piece))
			piece[i]++;
		*off_x += 1;
	}
	return (piece);
}

static int		is_better(t_filler *data, int x, int y, char *ptr)
{
	int			i;
	char		c;
	t_point		tmp;

	i = -1;
	tmp.x = -1;
	tmp.y = -1;
	c = ft_tolower(data->enemy);
	while (++i < data->map->rows)
		if ((ptr = ft_strchr(data->map->map[i], c)))
		{
			tmp.y = i;
			tmp.x = x >= ptr - data->map->map[i] ? ft_strrchr(data->map->map[i],
			c) - data->map->map[i] : ptr - data->map->map[i];
			break ;
		}
		else if (ft_strchr(data->map->map[i], data->enemy) && (tmp.y = i))
			tmp.x = ft_strchr_n(data->map->map[i], data->enemy);
	tmp.x += tmp.x <= x ? -3 : 3;
	tmp.y += tmp.y <= y ? -3 : 3;
	return ((ft_abs(x - tmp.x) * ft_abs(x - tmp.x)) + (ft_abs(y - tmp.y) *
			ft_abs(y - tmp.y)) < (ft_abs(data->point->x - tmp.x) *
			ft_abs(data->point->x - tmp.x)) + (ft_abs(data->point->y - tmp.y) *
			ft_abs(data->point->y - tmp.y)));
}

static int		try_paste(t_filler *data, char **piece, int x, int y)
{
	int			i;
	int			j;
	int			intersect;

	i = -1;
	intersect = 0;
	while (++i < data->piece->rows - data->point->off_y && (j = -1))
		while (++j < data->piece->cols - data->point->off_x)
		{
			if (piece[i][j] == '.')
				continue ;
			else if (y + i >= data->map->rows || x + j >= data->map->cols ||
			(piece[i][j] == '*' &&
			ft_toupper(data->map->map[y + i][x + j]) == data->enemy) ||
			(piece[i][j] == '*' &&
			ft_toupper(data->map->map[y + i][x + j]) == data->my && intersect))
				return (0);
			else if (piece[i][j] == '*' &&
				ft_toupper(data->map->map[y + i][x + j]) == data->my)
				intersect++;
		}
	return (intersect);
}

void			paste_figure(t_filler *data)
{
	int			i;
	int			j;
	char		**piece;

	i = -1;
	data->point->off_x = 0;
	data->point->off_y = 0;
	data->point->x = 0;
	data->point->y = 0;
	piece = cut_spare(data->piece->map, data->map->rows,
			&(data->point->off_x), &(data->point->off_y));
	while (++i < data->map->rows && (j = -1))
		while (++j < data->map->cols)
			if (try_paste(data, piece, j, i) &&
			((!data->point->x && !data->point->y) || is_better(data, j, i, 0)))
			{
				data->point->x = j;
				data->point->y = i;
			}
	make_upper(data);
	ft_printf("%d %d\n", data->point->y - data->point->off_y,
			data->point->x - data->point->off_x);
}
