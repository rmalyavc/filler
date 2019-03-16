/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:29:08 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/02/24 15:03:23 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		lst_clear(t_printf **lst)
{
	t_printf	*curr;
	t_printf	*prev;
	int			i;

	if (lst == NULL || *lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL && (prev = curr))
	{
		i = -1;
		curr = curr->next;
		while (prev->flags[++i] != NULL)
			free(prev->flags[i]);
		free(prev->flags);
		prev->flags = NULL;
		ft_strdel(&(prev->data));
		prev->next = NULL;
		free(prev);
	}
	*lst = NULL;
}

static int		inv_case(t_printf *lst, char **src, char c, int fd)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = *src;
	if (ft_str_search(lst->flags, "0") != -1 &&
			ft_str_search(lst->flags, "-") < 0)
		c = '0';
	while (ft_memchr("#0-+ hljz.*123456789L", ptr[1], 21) != NULL && (ptr += 1))
		*src += 1;
	if (lst->width > 0 && (i += lst->width - 1) &&
			ft_str_search(lst->flags, "-") < 0)
		while (--lst->width > 0)
			ft_putchar_fd(c, fd);
	else if (lst->width > 0)
	{
		*src += 1;
		ft_putchar_fd(ptr[1], fd);
		i++;
		while (--lst->width > 0)
			ft_putchar_fd(c, fd);
	}
	return (i);
}

static void		ft_getcolor(char **src)
{
	char	*ptr;

	ptr = *src;
	if (ft_strstr(ptr, "{red}") == ptr && (*src += 5))
		ft_putstr("\033[31m");
	else if (ft_strstr(ptr, "{green}") == ptr && (*src += 7))
		ft_putstr("\033[32m");
	else if (ft_strstr(ptr, "{brown}") == ptr && (*src += 7))
		ft_putstr("\033[33m");
	else if (ft_strstr(ptr, "{blue}") == ptr && (*src += 6))
		ft_putstr("\033[34m");
	else if (ft_strstr(ptr, "{purple}") == ptr && (*src += 8))
		ft_putstr("\033[35m");
	else if (ft_strstr(ptr, "{cyan}") == ptr && (*src += 6))
		ft_putstr("\033[36m");
	else if (ft_strstr(ptr, "{gray}") == ptr && (*src += 6))
		ft_putstr("\033[1;30m");
	else if (ft_strstr(ptr, "{eoc}") == ptr && (*src += 5))
		ft_putstr("\033[0m");
}

static size_t	ft_output(char *src, t_printf *lst, int i, int fd)
{
	char	c;

	c = ' ';
	while (src[0] != '\0')
	{
		if (src[0] == '{')
			ft_getcolor(&src);
		if (src[0] == '%' && lst != NULL && lst->spec == '\0')
			i += inv_case(lst, &src, c, fd);
		else if (src[0] == '%')
		{
			i += put_arg(lst, ft_str_search(lst->flags, "#"), 0, fd);
			src++;
			lst = lst->next;
			while (ft_strchr("sSpdDioOuUxXcCfFeE%", src[0]) == NULL)
				src++;
		}
		else if (src[0] != '\0' && (i += 1))
			ft_putchar_fd(src[0], fd);
		if (src[0] != '\0')
			src++;
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	*lst;
	t_printf	*curr;
	int			res;
	int			fd;

	va_start(ap, format);
	fd = 1;
	if (ft_strstr(format, "{_fd_}") == format && (format += 6))
		if ((fd = va_arg(ap, int)) == -1)
			fd = 1;
	lst = make_list((char *)format, "#0-+ hljz.*L", "sSpdDioOuUxXcCfFeE");
	push_data(ap, lst);
	curr = lst;
	res = ft_output((char *)format, lst, 0, fd);
	lst_clear(&lst);
	return (res);
}
