/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:49:00 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/18 13:48:25 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	merge_nums(uintmax_t num, uintmax_t rest, char *res)
{
	char	*num_s;
	char	*rest_s;

	ft_strcat(res, (num_s = ft_utoa_base(num, 10, -1)));
	num = rest;
	rest /= 100;
	if (num % 1000 != 0 && rest % 100 != 0)
		rest += rest % 100;
	if (rest > 0 && (rest_s = ft_utoa_base(rest, 10, -1)))
	{
		ft_strcat(res, ".");
		while (rest_s[ft_strlen(rest_s) - 1] == '0')
			rest_s[ft_strlen(rest_s) - 1] = '\0';
		ft_strcat(res, rest_s);
		ft_strdel(&rest_s);
	}
	ft_strdel(&num_s);
}

static void	precision(char *res, char *start, int prec)
{
	if (start == NULL && (ft_strcat(res, ".")))
		start = ft_strchr(res, '.');
	start++;
	if (prec > (int)ft_strlen(start))
		ft_memset(&start[ft_strlen(start)], '0', prec - ft_strlen(start));
}

char		*ft_ftoa(long double nb, int prec)
{
	uintmax_t	num;
	uintmax_t	rest;
	char		*res;

	res = ft_strnew(36);
	if (nb < 0 && (nb *= -1))
		res[0] = '-';
	num = ((uintmax_t)nb);
	rest = (nb - num) * 100000000000000000;
	merge_nums(num, rest, res);
	if (prec > 0)
		precision(res, ft_strchr(res, '.'), prec);
	return (res);
}
