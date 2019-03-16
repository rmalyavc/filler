/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:57:53 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/16 17:21:31 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_data(t_filler *data, char *info)
{
	char	*res;

	data->map = (t_map *)malloc(sizeof(t_map));
	data->piece = (t_map *)malloc(sizeof(t_map));
	if (!info || !data->map || !data->piece ||
		(!(res = ft_strstr(line, "p1")) && !ft_strstr(line, "p2")))
		return (0);
	data->my = res ? 'O' : 'X';
	data->enemy = data->my == 'O' ? 'X' : 'O';
	data->map->map = NULL;
	data->piece->map = NULL;
	data->map->cols = 0;
	data->map->rows = 0;
	data->piece->cols = 0;
	data->piece->rows = 0;
	return (1);
}
