/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:55:59 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:56:04 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_free_gnl(void *ptr, int ret)
{
	free(ptr);
	return (ret);
}

static int	ten_in_static(char **st, char **line)
{
	char	*loc;
	char	*br;

	if (*st == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	br = ft_strchr(*st, '\n');
	if (br)
	{
		*br = 0;
		*line = ft_strdup(*st);
		if (!(*line))
			return (-1);
		loc = *st;
		*st = ft_strdup(++br);
		if (!(*st))
			return (ft_free_gnl(loc, -1));
		return (ft_free_gnl(loc, 1));
	}
	*line = (*st);
	(*st) = 0;
	return (0);
}

static int	end_text(char **st, char **line, char **buff)
{
	char	*loc;
	char	*br;
	int		ret;

	ret = 0;
	br = ft_strchr(*buff, '\n');
	if (br)
	{
		*br = 0;
		loc = *st;
		*st = ft_strdup(++br);
		if (!(*st))
			return (ft_free_gnl(loc, -1));
		ret = ft_free_gnl(loc, 1);
	}
	loc = *line;
	*line = ft_strjoin(*line, *buff);
	if (!(*line))
		return (ft_free_gnl(loc, -1));
	return (ft_free_gnl(loc, ret));
}

static int	buffer_checker(char **st, char **line, char fd, int buffers)
{
	char	*buff;
	int		fd_r;

	buff = malloc(buffers + 1);
	if (!buff)
		return (-1);
	fd_r = read(fd, buff, buffers);
	while (fd_r > 0)
	{
		buff[fd_r] = 0;
		fd_r = end_text(st, line, &buff);
		if (fd_r != 0)
			return (ft_free_gnl(buff, fd_r));
	}
	free(buff);
	return (0);
}

int	get_next_line(int fd, char **line, int buffers)
{
	static char	*st[1025];
	int			ret;

	ret = 0;
	if (buffers < 1 || !line || read(fd, 0, 0))
		return (-1);
	ret = ten_in_static(&st[fd], line);
	if (ret == 0)
		return (buffer_checker(&st[fd], line, fd, buffers));
	return (ret);
}
