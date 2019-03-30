/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:57:53 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/30 18:22:27 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_data(t_filler *data, char *info)
{
	char	*res;

	data->map = (t_map *)malloc(sizeof(t_map));
	data->piece = (t_map *)malloc(sizeof(t_map));
	data->point = (t_point *)malloc(sizeof(t_point));
	if (!info || !data->map || !data->piece ||
		(!(res = ft_strstr(info, "p1")) && !ft_strstr(info, "p2")))
		return (0);
	data->my = res ? 'O' : 'X';
	data->enemy = data->my == 'O' ? 'X' : 'O';
	data->map->map = NULL;
	data->piece->map = NULL;
	data->map->cols = 0;
	data->map->rows = 0;
	data->piece->cols = 0;
	data->piece->rows = 0;
	data->point->x = 0;
	data->point->y = 0;
	data->point->off_x = 0;
	data->point->off_y = 0;
	data->point->score = 0;
	return (1);
}
