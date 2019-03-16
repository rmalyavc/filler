/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:24:55 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/01/20 20:44:52 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		arr_size(int arr[])
{
	int		i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

static size_t	count_bytes(char *str)
{
	int		qty;

	qty = 21;
	if (ft_strlen(str) < 12)
		qty = 11;
	else if (ft_strlen(str) < 17)
		qty = 16;
	return (qty);
}

static void		write_byte(unsigned char *buff, char *ptr, char *bytes, int nb)
{
	int		size;

	size = 0;
	if (buff == NULL || ptr == NULL)
		return ;
	if (ft_strlen(ft_strchr(ptr, '1')) < 8)
	{
		buff[ft_strlen((char *)buff)] = nb;
		return ;
	}
	ft_strcpy(bytes, "110");
	if ((size = count_bytes(ft_strchr(ptr, '1'))) == 16)
		ft_memmove(&bytes[2], &bytes[1], 3);
	else if (size > 16 && (ptr += (ft_strlen(ptr) - size)))
		ft_memmove(&bytes[2], &bytes[0], 4);
	ft_strncat(bytes, ptr, (size = 8 - ft_strlen(bytes)));
	buff[ft_strlen((char *)buff)] = ft_atoi_base(bytes, 2);
	while ((ft_memmove(ptr, ptr + size, ft_strlen(ptr + size) + 1)) &&
			ft_strlen(ptr) > 0)
	{
		ft_strcpy(bytes, "10");
		ft_strncat(bytes, ptr, (size = 6));
		buff[ft_strlen((char *)buff)] = ft_atoi_base(bytes, 2);
	}
}

unsigned char	*ft_unicode(int arr[])
{
	unsigned char	buff[arr_size(arr) * 3 + 1];
	char			*ptr;
	char			*tmp;
	char			bytes[9];
	int				i;

	if (!arr)
		return (NULL);
	ft_bzero(bytes, 9);
	ft_bzero(buff, arr_size(arr) * 3 + 1);
	i = -1;
	while (arr[++i] && (tmp = ft_itoa_base(arr[i], 2, 0)))
	{
		ptr = ft_itoa_base(arr[i], 2, count_bytes(tmp));
		write_byte(buff, ptr, bytes, arr[i]);
		ft_strdel(&tmp);
		ft_strdel(&ptr);
	}
	return ((unsigned char *)ft_strdup((const char *)buff));
}
