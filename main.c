/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:24:01 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/16 21:32:33 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				main(void)
{
	int			i;
	char		*line;
	t_filler	game_data;

	if ((!get_next_line(0, &line) || !init_data(&game_data, line)) &&
		ft_printf("{red}Error!{eoc}\n"))
		exit(0);
	start_game(&game_data);
	return (1);
}
