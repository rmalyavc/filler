/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:09:38 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/25 20:23:48 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>

size_t	ft_file_size(int fd)
{
	int		ret;
	size_t	i;
	char	buffer[2];

	i = 0;
	while ((ret = read(fd, &buffer[0], 1)))
		i++;
	close(fd);
	return (i);
}
