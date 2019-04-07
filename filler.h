/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:06:44 by rmalyavc          #+#    #+#             */
/*   Updated: 2019/03/30 18:25:47 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			off_x;
	int			off_y;
	int			score;
}				t_point;

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
	t_point		*point;
}				t_filler;

int				init_data(t_filler *data, char *line);
int				get_data(t_filler *data);
void			paste_figure(t_filler *data);
void			make_upper(t_filler *data);

#endif
