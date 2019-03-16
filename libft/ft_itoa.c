/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:27:40 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/19 22:31:38 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	define_len(int n)
{
	int		i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = define_len(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	ft_strclr(res);
	if (n == -2147483648)
	{
		ft_strcpy(res, "-2147483648");
		return (res);
	}
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	while (n > 0 || (n == 0 && len == 1 && res[0] != '-'))
	{
		res[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (res);
}
