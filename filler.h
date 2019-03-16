/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:06:44 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/16 21:32:20 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft/includes/libft.h"

typedef struct	s_map
{
	int			cols;
	int			rows;
	char		**map;
}				t_map;

typedef struct	s_filler
{
	char		my;
	char		enemy;
	t_map		*map;
	t_map		*piece;
}				t_filler;

int				init_data(t_filler *data, char *line);
void			start_game(t_filler *data);
int				get_data(t_filler *data);

#endif
