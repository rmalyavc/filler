/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:12:36 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/03/30 20:14:27 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static t_list	*search_elem(const int fd, t_list **lst)
{
	t_list	*elem;

	elem = *lst;
	while (elem != NULL)
	{
		if (elem->content_size == (size_t)fd)
			return (elem);
		elem = elem->next;
	}
	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->next = NULL;
	elem->content_size = (size_t)fd;
	elem->content = NULL;
	ft_lstadd(lst, elem);
	return (elem);
}

static char		*ft_realloc(char **line, int flag)
{
	char	*buffer;

	if (*line == NULL || flag == -1)
		*line = ft_strnew(BUFF_SIZE);
	else
	{
		if (flag == 0)
		{
			buffer = ft_strnew(ft_strlen(*line) + BUFF_SIZE);
			ft_strcpy(buffer, *line);
		}
		else
		{
			buffer = ft_strnew(ft_strlen(*line));
			ft_strcpy(buffer, *line);
		}
		ft_strdel(line);
		*line = buffer;
	}
	return (*line);
}

static int		read_buff(t_list **elem, char **line)
{
	t_list	*curr;
	char	*ptr;

	curr = *elem;
	if (curr->content != NULL && (ptr = ft_strchr(curr->content,
		'\n')) != curr->content && ptr != NULL)
	{
		ptr += 1;
		*line = ft_strnew(ptr - (char *)curr->content);
		ft_memmove(*line, curr->content, ptr - (char *)curr->content - 1);
		ft_memmove(curr->content, ptr, ft_strlen(ptr) + 1);
		return (1);
	}
	if (curr->content != NULL && ft_strlen(curr->content) > 0)
	{
		*line = ft_strnew(ft_strlen(curr->content));
		ft_strcpy(*line, curr->content);
		ft_strclr(curr->content);
		return (1);
	}
	return (0);
}

static int		file_to_str(const int fd, t_list **lst, char **line)
{
	t_list	*curr;
	int		res;
	char	buffer[BUFF_SIZE + 1];
	char	*ptr;

	ft_bzero(buffer, BUFF_SIZE + 1);
	curr = search_elem(fd, lst);
	while ((res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		ptr = curr->content;
		curr->content = ft_realloc(&ptr, 0);
		ft_strcat(curr->content, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	if (res == -1)
		return (-1);
	if (read_buff(&curr, line) == 1)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	res = file_to_str(fd, &lst, line);
	if (res == 1)
		return (1);
	else if (res == -1)
		return (-1);
	return (0);
}
