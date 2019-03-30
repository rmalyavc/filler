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
	while (++i < size && !ft_strchr(piece[i], '*')) {
		piece++;
		*off_y += 1;
	}
	while (need_offset_x(piece, ft_count_strings(piece)) && (i = -1))
	{
		while (++i < (int)ft_count_strings(piece))
			piece[i]++;
		*off_x += 1;
	}
	return (piece);
}

static int		try_paste(t_filler *data, char **piece, int x, int y)
{
	int			i;
	int			j;
	int			intersection;
int fd = open("test1", O_WRONLY | O_APPEND);
	i = -1;
	intersection = 0;
ft_printf("{_fd_}X = %d Y = %d\n", fd, x, y);
	while (++i < data->piece->rows - data->point->off_y && (j = -1))
		while (++j < data->piece->cols - data->point->off_x)
		{
ft_printf("{_fd_}J = %d I = %d\n", fd, j, i);
			if (((y + i >= data->map->rows || x + j >= data->map->cols) && piece[i][j] == '*') ||
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
	int			off_x;
	int			off_y;
	char		**piece;
int fd = open("test1", O_WRONLY | O_APPEND);
	i = -1;
	off_x = 0;
	off_y = 0;
	piece = cut_spare(data->piece->map, data->map->rows, &off_x, &off_y);
	print_map_piece(data);
	while (++i < data->map->rows && (j = -1))
	{
		while (++j < data->map->cols)
			if (try_paste(data, piece, j, i))
			{
				data->point->x = j;
				data->point->y = i;
				data->point->off_x = off_x;
				data->point->off_y = off_y;
				break ;
			}
	}
ft_printf("{_fd_}RESX = %d RESY = %d\n", fd, data->point->x - data->point->off_x, data->point->y - data->point->off_y);
	// ft_printf("%d %d\n", data->point->y - data->point->off_y, data->point->x - data->point->off_x);
	ft_putnbr(data->point->y - data->point->off_y);
	ft_putchar(' ');
	ft_putnbr(data->point->x - data->point->off_x);
	ft_putchar('\n');
}
