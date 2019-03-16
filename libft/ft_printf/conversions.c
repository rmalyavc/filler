/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:03:19 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/21 16:26:34 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_char(va_list ap, t_printf *elem, int len)
{
	int		arr[2];

	arr[1] = 0;
	if (ft_str_search(elem->flags, "l") != -1 &&
			(arr[0] = va_arg(ap, int)) != 0)
	{
		elem->data = (char *)ft_unicode(arr);
		elem->spec = 's';
	}
	else if ((elem->data = ft_strnew(1)) &&
			ft_str_search(elem->flags, "l") < 0)
		if ((len = va_arg(ap, int)) != 0)
			elem->data[0] = len;
}

void		float_num(va_list ap, t_printf *elem, int prec)
{
	long double	nb;

	if (ft_str_search(elem->flags, "l") < 0)
		nb = va_arg(ap, double);
	else
		nb = (long double)va_arg(ap, double);
	if (elem->spec == 'f')
		elem->data = ft_ftoa(nb, 15);
	else
		elem->data = ft_fetoa(nb, prec);
}

void		signed_num(va_list ap, t_printf *elem, int prec)
{
	intmax_t	nb;

	if (ft_str_search(elem->flags, "l") != -1)
		nb = va_arg(ap, long int);
	else if (ft_str_search(elem->flags, "ll") != -1 ||
			ft_str_search(elem->flags, "z") != -1)
		nb = va_arg(ap, long long int);
	else if (ft_str_search(elem->flags, "h") != -1)
		nb = (short int)va_arg(ap, int);
	else if (ft_str_search(elem->flags, "j") != -1)
		nb = va_arg(ap, intmax_t);
	else
		nb = va_arg(ap, int);
	if (nb < 0)
		prec++;
	if (ft_str_search(elem->flags, "hh") != -1 &&
			ft_str_search(elem->flags, "l") < 0)
		elem->data = ft_itoa_base((char)nb, 10, prec);
	else
		elem->data = ft_itoa_base(nb, 10, prec);
}

void		unsigned_num(va_list ap, t_printf *elem, int base, int prec)
{
	uintmax_t	nb;

	if (ft_str_search(elem->flags, "p") != -1)
		nb = va_arg(ap, void *) - NULL;
	else if (ft_str_search(elem->flags, "l") != -1)
		nb = va_arg(ap, unsigned long int);
	else if (ft_str_search(elem->flags, "ll") != -1)
		nb = va_arg(ap, unsigned long long int);
	else if (ft_str_search(elem->flags, "z") != -1)
		nb = va_arg(ap, size_t);
	else if (ft_str_search(elem->flags, "h") != -1)
		nb = (unsigned short int)va_arg(ap, unsigned int);
	else if (ft_str_search(elem->flags, "j") != -1)
		nb = va_arg(ap, uintmax_t);
	else
		nb = va_arg(ap, unsigned int);
	if (ft_memchr("xXo", elem->spec, 3) && (base = 16))
		if (elem->spec == 'o')
			base = 8;
	if (ft_str_search(elem->flags, "hh") != -1 &&
			ft_str_search(elem->flags, "l") == -1)
		nb = (unsigned char)nb;
	elem->data = ft_utoa_base(nb, base, prec);
	if (elem->spec == 'x')
		ft_str_low(elem->data);
}

void		ft_string(va_list ap, t_printf *elem, int len, char *ptr)
{
	if (elem->spec == 's')
	{
		if (ft_str_search(elem->flags, "l") != -1)
			if ((elem->data = (char *)ft_unicode(va_arg(ap, wchar_t *))))
				len = unicut(len, (unsigned char *)elem->data);
		if (ft_str_search(elem->flags, "l") < 0 && (ptr = va_arg(ap, char *)))
			elem->data = ft_strdup(ptr);
		if (elem->data == NULL)
			elem->data = ft_strdup("(null)");
		if (len > 0 && (int)ft_strlen(elem->data) > len)
			elem->data[len] = '\0';
	}
	else
		ft_char(ap, elem, len);
}
