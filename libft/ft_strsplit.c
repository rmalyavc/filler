/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:16:23 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/19 21:18:41 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	count_params(char const *str, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (str[i] == c)
		i++;
	if (str[i] != '\0')
		counter = 1;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && str[i] == c && str[i + 1])
			counter++;
		i++;
	}
	return (counter);
}

static int	count_size(int start, char const *str, char c)
{
	int		i;

	i = 0;
	while (str[start] != c && str[start] != '\0')
	{
		start++;
		i++;
	}
	return (i);
}

static char	*ft_cpy_range(char *dst, char const *src, int n, int start)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	define_start(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**buffer;

	j = 0;
	if (s == NULL)
		return (NULL);
	buffer = (char **)malloc(sizeof(char *) * count_params(s, c) + 1);
	i = define_start((char *)s, c);
	while (buffer != NULL && s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			buffer[j] = (char *)malloc(sizeof(char) * count_size(i, s, c) + 1);
			if (buffer[j] == NULL)
				return (NULL);
			ft_cpy_range(buffer[j], s, count_size(i, s, c), i);
			j++;
		}
		i++;
	}
	if (buffer != NULL)
		buffer[j] = 0;
	return (buffer);
}
