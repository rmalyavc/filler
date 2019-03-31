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

void    print_map_piece(t_filler *data) {
	int fd = open("test1", O_WRONLY | O_APPEND);
	int i = -1;

	ft_printf("{_fd_}Map Rows = %d\nMap Cols = %d\n", fd, data->map->rows, data->map->cols);
	while (++i < data->map->rows)
		ft_printf("{_fd_}%s\n", fd, data->map->map[i]);
	ft_printf("{_fd_} \nPiece Rows = %d\nPiece Cols = %d\n", fd, data->piece->rows, data->piece->cols);
	i = -1;
	while (++i < data->piece->rows)
		ft_printf("{_fd_}%s\n", fd, data->piece->map[i]);
}

void	print_piece(char **piece) {
	int fd = open("test1", O_WRONLY | O_APPEND);
	int i = -1;

	while (++i < ft_count_strings(piece))
		ft_printf("{_fd_}%s\n", fd, piece[i]);
}

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
	while (++i < size && !ft_strchr(piece[i - *off_y], '*')) {
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

static int		is_better(t_filler *data, int x, int y)
{
	int			i;
	t_point		tmp;
int fd = open("test1", O_WRONLY | O_APPEND);
	i = -1;
	tmp.x = -1;
	tmp.y = -1;
	while (++i < data->map->rows)
	{
		// if (ft_strchr(data->map->map[i], data->enemy) && ((tmp.y = i) || 1))
		// 	tmp.x = ft_strchr_n(data->map->map[i], data->enemy);
		if (ft_strchr(data->map->map[i], ft_tolower(data->enemy)))
		{
			tmp.y = i;
			tmp.x = ft_strchr_n(data->map->map[i], ft_tolower(data->enemy));
			break ;
		}
	}
	return (ft_abs((x * x + y * y) - (tmp.x * tmp.x - tmp.y * tmp.y)) >
	ft_abs((data->point->x * data->point->x + data->point->y * data->point->y) - (tmp.x * tmp.x - tmp.y * tmp.y)));
}	

static int		try_paste(t_filler *data, char **piece, int x, int y)
{
	int			i;
	int			j;
	int			intersection;
// int fd = open("test1", O_WRONLY | O_APPEND);
	i = -1;
	intersection = 0;
// ft_printf("{_fd_}X = %d Y = %d\n", fd, x, y);
	while (++i < data->piece->rows - data->point->off_y && (j = -1))
		while (++j < data->piece->cols - data->point->off_x)
		{
// ft_printf("{_fd_}J = %d I = %d\n", fd, j, i);
			if (piece[i][j] == '.')
				continue ;
			else if (y + i >= data->map->rows || x + j >= data->map->cols ||
				(piece[i][j] == '*' && ft_toupper(data->map->map[y + i][x + j]) == data->enemy) ||
				(piece[i][j] == '*' && ft_toupper(data->map->map[y + i][x + j]) == data->my && intersection))
				return (0);
			else if (piece[i][j] == '*' && ft_toupper(data->map->map[y + i][x + j]) == data->my)
				intersection++;
		}
	return (intersection);
}

void			paste_figure(t_filler *data)
{
	int			i;
	int			j;
	char		**piece;
int fd = open("test1", O_WRONLY | O_APPEND);
	i = -1;

	data->point->off_x = 0;
	data->point->off_y = 0;
	data->point->x = 0;
	data->point->y = 0;
print_map_piece(data);
	piece = cut_spare(data->piece->map, data->map->rows, &(data->point->off_x), &(data->point->off_y));
ft_printf("{_fd_}After cut_spare\n\n", fd);
print_piece(piece);
	
	while (++i < data->map->rows && (j = -1))
		while (++j < data->map->cols) {	
			if (try_paste(data, piece, j, i) && ((!data->point->x && !data->point->y) || is_better(data, j, i)))
			{
				data->point->x = j;
				data->point->y = i;
			}
		}

ft_printf("{_fd_}%d %d\n", fd, data->point->y - data->point->off_y, data->point->x - data->point->off_x);
	ft_printf("%d %d\n", data->point->y - data->point->off_y, data->point->x - data->point->off_x);
	// ft_putnbr(data->point->y - data->point->off_y);
	// ft_putchar(' ');
	// ft_putnbr(data->point->x - data->point->off_x);
	// ft_putchar('\n');
}
