/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:33:08 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/29 15:17:54 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_end(t_fd *list, char **line)
{
	char	*ptr;

	if ((ptr = ft_strchr(list->str, '\0')))
	{
		if (ptr == list->str)
		{
			*line = list->str;
			return (0);
		}
		*line = ft_strdup(list->str);
		list->str = ptr;
		return (1);
	}
	return (0);
}

static int		ft_gnl(t_fd *list, char *buff, char **line)
{
	int				ret;
	char			*ptr;
	char			*l;
	char			*s;

	if (!list->str)
		list->str = ft_strnew(1);
	while (!(ptr = ft_strchr(list->str, '\n')) && \
			(ret = read(list->fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		l = ft_strjoin(list->str, buff);
		free(list->str);
		list->str = l;
	}
	if ((ptr = ft_strchr(list->str, '\n')))
	{
		*ptr++ = '\0';
		*line = ft_strdup(list->str);
		s = list->str;
		list->str = ft_strdup(ptr);
		free(s);
		return (1);
	}
	return (check_end(list, line));
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*list = NULL;
	t_fd			*elem;
	char			buff[BUFF_SIZE + 1];

	elem = list;
	if (fd < 0 || !line || (read(fd, buff, 0) < 0))
		return (-1);
	while (elem)
	{
		if (elem->fd == fd)
			return (ft_gnl(elem, buff, line));
		elem = elem->next;
	}
	if (!elem)
	{
		if (!(elem = (t_fd *)malloc(sizeof(t_fd))))
			return (-1);
		elem->fd = fd;
		elem->str = NULL;
		elem->next = list;
		list = elem;
	}
	return (ft_gnl(list, buff, line));
}
