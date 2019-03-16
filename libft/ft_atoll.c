/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:52:37 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/02/24 15:04:28 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*cut_spare(const char *s)
{
	char	*buffer;
	int		i;

	i = 0;
	while (s[0] == ' ' || s[0] == '\t' || s[0] == '\n' ||
			s[0] == '\r' || s[0] == '\f' || s[0] == '\v')
		s += 1;
	if (s[0] == '+' && s[1] >= '0' && s[1] <= '9')
		s += 1;
	else if ((s[0] == '-' || s[0] == '+') && (s[1] < '0' || s[1] > '9'))
		return (NULL);
	while ((s[i] >= '0' && s[i] <= '9') || (i == 0 && s[i] == '-'))
		i++;
	buffer = (char *)malloc(sizeof(char) * i + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[i] = '\0';
	while (--i >= 0)
		buffer[i] = s[i];
	return (buffer);
}

long long int	ft_atoll(const char *str)
{
	int				i;
	long long int	res;
	long long int	factor;
	char			*ptr;

	factor = 1;
	res = 0;
	ptr = cut_spare(str);
	if (ptr == NULL)
		return (0);
	i = ft_strlen(ptr);
	while (--i >= 0)
	{
		if (ptr[i] == '-')
		{
			free(ptr);
			return (-res);
		}
		res += (ptr[i] - '0') * factor;
		factor *= 10;
	}
	free(ptr);
	return (res);
}
