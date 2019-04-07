/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:24:01 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/30 18:17:16 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <time.h>

void			make_upper(t_filler *data)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->map->rows && (j = -1))
		while (++j < data->map->rows)
			if (data->map->map[i][j] == ft_tolower(data->enemy))
				data->map->map[i][j] = data->enemy;
}

int				main(void)
{
	char		*line;
	t_filler	game_data;

	get_next_line(0, &line);
	init_data(&game_data, line);
	while (get_data(&game_data))
	{
		paste_figure(&game_data);
	}
	return (1);
}
