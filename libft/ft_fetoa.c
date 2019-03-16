/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:33:41 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/18 20:44:06 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	merge_nums(uintmax_t num, uintmax_t rest, char *res, int prec)
{
	char	*num_s;
	char	*rest_s;

	ft_strcat(res, (num_s = ft_utoa_base(num, 10, -1)));
	num = rest;
	rest /= 100;
	if ((num / 10) % 10 > 4)
		rest++;
	if (rest > 0 && (rest_s = ft_utoa_base(rest, 10, prec)))
	{
		ft_strcat(res, ".");
		while (rest_s[ft_strlen(rest_s) - 1] == '0')
			rest_s[ft_strlen(rest_s) - 1] = '\0';
		ft_strcat(res, rest_s);
		ft_strdel(&rest_s);
	}
	ft_strdel(&num_s);
}

static void	precision(char *res, char *start, int prec, char *exp)
{
	if (prec > 0)
	{
		if (start == NULL && (ft_strcat(res, ".")))
			start = ft_strchr(res, '.');
		start++;
		if (prec > (int)ft_strlen(start))
			ft_memset(&start[ft_strlen(start)], '0', prec - ft_strlen(start));
		else
			start[prec] = '\0';
	}
	if ((res[ft_strlen(res)] = 'e') && exp[0] != '-')
		ft_strcat(res, "+");
	if (exp[0] != '-')
		ft_memmove(exp, exp + 1, ft_strlen(exp) + 1);
	ft_strcat(res, exp);
	ft_strdel(&exp);
}

char		*ft_fetoa(long double nb, int prec)
{
	uintmax_t	num;
	uintmax_t	rest;
	char		*res;
	int			i;

	i = 0;
	res = ft_strnew(36);
	if (nb < 0 && (nb *= -1))
		res[0] = '-';
	while ((uintmax_t)nb == 0 && (nb *= 10))
		i--;
	while (i > -1 && ((uintmax_t)nb / 10) % 10 != 0 && (nb /= 10))
		i++;
	num = ((uintmax_t)nb);
	rest = (nb - num) * ft_power(10, prec + 2);
	merge_nums(num, rest, res, prec);
	precision(res, ft_strchr(res, '.'), prec, ft_itoa_base(i, 10, 3));
	return (res);
}
