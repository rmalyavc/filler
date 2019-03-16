/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:10:41 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/30 17:11:00 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct		s_printf
{
	char			**flags;
	char			spec;
	char			*data;
	int				width;
	struct s_printf	*next;
}					t_printf;

void				push_data(va_list ap, t_printf *lst);
t_printf			*make_list(char *src, char *flags, char *specs);
int					ft_printf(const char *format, ...);
int					put_arg(t_printf *lst, int flag, int i, int fd);
void				float_num(va_list ap, t_printf *elem, int prec);
void				signed_num(va_list ap, t_printf *elem, int prec);
void				unsigned_num(va_list ap, t_printf *elem, int base,
					int prec);
void				ft_string(va_list ap, t_printf *elem, int len, char *ptr);
int					unicut(int len, unsigned char *str);

#endif
