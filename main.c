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

int				main(void)
{
	char		*line;
	t_filler	game_data;

		// int fd = open("test1", O_WRONLY | O_APPEND);
		// int i = 0;
	get_next_line(0, &line);
	init_data(&game_data, line);
	// 
	//ft_printf("{_fd_}%s\nRows = %d Cols = %d", fd, line, game_data.map->rows, game_data.map->cols);
	//ft_print_buff(game_data.map->map);
	//if ((!get_next_line(0, &line) || !init_data(&game_data, line)) &&
	//	ft_printf("{red}Error!{eoc}\n"))
	//	exit(0);
	//ft_putstr_fd(line, fd);
	// ft_printf("{_fd_}Before READ\n", fd);
	// clock_t begin = clock();

	// get_data(&game_data);
	
	// clock_t end = clock();
	// ft_printf("{_fd_}After READ: %f\n", fd, (double)(end - begin));
	
	// end = clock();
	
	// paste_figure(&game_data);
	
	// ft_printf("{_fd_}After PASTE = %f\n", fd, (double)(end - begin));
	while (get_data(&game_data)) {
		// clock_t end = clock();
		// ft_printf("{_fd_}After READ\n", fd);
		// ft_printf("{_fd_}Try\n", fd);
		paste_figure(&game_data);
	}
	return (1);
}
