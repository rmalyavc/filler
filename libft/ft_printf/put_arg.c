/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:45:16 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/20 19:26:35 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sharp_case(t_printf *elem, int flag, char c, int fd)
{
	int		i;

	i = 0;
	if ((elem->data != NULL && flag != -1 && ft_strcmp(elem->data, "0") != 0 &&
				elem->data[0] != '\0') || ft_str_search(elem->flags, "p") != -1)
	{
		if (ft_str_search(elem->flags, "p") != -1)
			elem->width -= 2;
		while (c != '0' && elem->width > 0 && ft_str_search(elem->flags,
					"-") == -1 && elem->width-- > (int)ft_strlen(elem->data))
		{
			ft_putchar_fd(c, fd);
			i++;
		}
		if (elem->spec == 'o' && elem->data[0] != '0' && (i += 1))
			ft_putchar_fd('0', fd);
		else if (elem->spec == 'x' && (i += 2))
			ft_putstr_fd("0x", fd);
		else if (elem->spec == 'X' && (i += 2))
			ft_putstr_fd("0X", fd);
	}
	return (i);
}

static int	space_case(t_printf *elem, int space, char c, int fd)
{
	char	sp;

	sp = elem->spec;
	if (space != -1 && ft_str_search(elem->flags, "+") < 0 && (sp == 'd' ||
				sp == 'i') && ((int)ft_strlen(elem->data) > elem->width ||
					c == '0') && elem->data[0] != '-')
	{
		elem->width--;
		ft_putchar_fd(' ', fd);
		return (1);
	}
	return (0);
}

static int	minus_case(t_printf *elem, int min, char c, int fd)
{
	int		i;
	int		plus;

	i = 0;
	plus = ft_str_search(elem->flags, "+");
	if (min != -1 && (elem->spec != 'c' || elem->data[0] != '\0'))
	{
		if (ft_memchr("di", elem->spec, 2) && plus != -1 &&
				elem->data[0] != '-' && (elem->width -= 1))
		{
			i++;
			ft_putchar_fd('+', fd);
		}
		ft_putstr_fd(elem->data, fd);
		i += ft_strlen(elem->data);
		while (elem->width-- > (int)ft_strlen(elem->data))
		{
			ft_putchar_fd(c, fd);
			i++;
		}
	}
	return (i);
}

static int	plus_case(t_printf *elem, char c, int fd, int i)
{
	int		plus;

	if ((plus = ft_str_search(elem->flags, "+")) &&
			ft_str_search(elem->flags, "-") != -1)
		return (i);
	if (ft_memchr("di", elem->spec, 2) && plus != -1 &&
			elem->data[0] != '-' && (elem->width -= 1))
		if (c == '0' && (i += 1))
			ft_putchar_fd('+', fd);
	if (elem->data[0] == '-' && c == '0' && (elem->width -= 1))
	{
		i++;
		ft_putchar_fd('-', fd);
		ft_memmove(elem->data, elem->data + 1, ft_strlen(elem->data) + 2);
	}
	while ((elem->spec != 'p' || c != '0') &&
			elem->width-- > (int)ft_strlen(elem->data))
		if ((i += 1))
			ft_putchar_fd(c, fd);
	if (ft_memchr("di", elem->spec, 2) && elem->data[0] != '-' &&
			c != '0' && plus != -1 && (i += 1))
		ft_putchar_fd('+', fd);
	ft_putstr_fd(elem->data, fd);
	i += ft_strlen(elem->data);
	return (i);
}

int			put_arg(t_printf *lst, int flag, int i, int fd)
{
	char	c;

	c = ' ';
	if (ft_str_search(lst->flags, "0") != -1 &&
			ft_str_search(lst->flags, "-") < 0 &&
			(ft_str_search(lst->flags, ".") < 0 ||
			ft_memchr("scp%", lst->spec, 4)))
		c = '0';
	if ((flag != -1 && lst->spec == 'o' && lst->data[0] != '0') ||
			(lst->spec == 'c' && lst->data[0] == '\0'))
		lst->width--;
	else if (flag != -1 && ft_tolower(lst->spec) == 'x' && lst->width > 1)
		lst->width -= 2;
	i += sharp_case(lst, flag, c, fd);
	i += space_case(lst, ft_str_search(lst->flags, " "), c, fd);
	i += minus_case(lst, ft_str_search(lst->flags, "-"), c, fd);
	i += plus_case(lst, c, fd, 0);
	if (lst->spec == 'c' && lst->data[0] == '\0' && (i += 1))
		ft_putchar_fd('\0', fd);
	while (lst->width-- > (int)ft_strlen(lst->data))
	{
		i++;
		ft_putchar_fd(c, fd);
	}
	return (i);
}
