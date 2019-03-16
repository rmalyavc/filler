/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:44:36 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/20 20:22:43 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			unicut(int len, unsigned char *str)
{
	int		i;
	int		counter;

	i = len;
	counter = 0;
	if (str == NULL || len > (int)ft_strlen((char *)str))
		return (len);
	while (str[--i] > 127 && str[i] < 192)
		counter++;
	if ((str[i] > 239 && counter != 3) || (str[i] > 223 && str[i] < 240 &&
				counter != 2) || (str[i] > 191 && str[i] < 224 && counter != 1))
		return (i);
	return (len);
}

static int	define_width(t_printf *elem, va_list ap, int i, int len)
{
	char	*pos;

	while ((pos = elem->flags[++i]) && pos[0] != '.' && pos != NULL)
		if (ft_isdigit(pos[0]) != 0 && pos[0] != '0')
			elem->width = ft_atoi(pos);
		else if (pos[0] == '*' && (elem->width = va_arg(ap, int)))
			if (elem->width < 0 && (elem->width *= -1))
				elem->flags[ft_count_strings(elem->flags)] = ft_strdup("-");
	if (pos && pos[0] == '.')
	{
		if (!(pos = elem->flags[i + 1]) ||
				(pos[0] != '*' && ft_isdigit(pos[0]) == 0))
			len = 0;
		else if (ft_isdigit(pos[0]) != 0)
			len = ft_atoi(pos);
		else if (pos[0] == '*')
			len = va_arg(ap, int);
		if (len < 0)
			elem->flags[i][0] = '\0';
	}
	if ((elem->spec == 'f' || elem->spec == 'e') && len == -2)
		len = 6;
	return (len);
}

void		push_data(va_list ap, t_printf *lst)
{
	int		len;

	while (lst != NULL)
	{
		len = define_width(lst, ap, -1, -2);
		if (ft_memchr("di", lst->spec, 2))
			signed_num(ap, lst, len);
		else if (ft_memchr("oxXu", lst->spec, 4))
			unsigned_num(ap, lst, 10, len);
		else if (ft_memchr("sc", lst->spec, 2))
			ft_string(ap, lst, len, NULL);
		else if (ft_memchr("fe", lst->spec, 2))
			float_num(ap, lst, len);
		if (lst->spec == 'f')
			len += (ft_strchr(lst->data, '.') + 1) - lst->data;
		if (lst->data != NULL && ft_atoi(lst->data) == 0 && len == 0 &&
				(ft_memchr("xXuUdisf", lst->spec, 8) ||
				(ft_tolower(lst->spec) == 'o' &&
				ft_str_search(lst->flags, "#") < 0)))
			lst->data[0] = '\0';
		else if (lst->data && ft_memchr("sf", lst->spec, 2) &&
				len < (int)ft_strlen(lst->data))
			lst->data[len] = '\0';
		lst = lst->next;
	}
}
