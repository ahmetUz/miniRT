/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:53:18 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/19 10:06:10 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_chr_lbreak(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '\n')
			return (&line[i]);
		++i;
	}
	return (NULL);
}

static char	*ft_prev_update(char *prev_line, char *pos)
{
	char	*res;

	if (!pos)
		return (NULL);
	++pos;
	res = ft_buffer_cat(prev_line, pos, ft_gnl_strlen(pos));
	*pos = '\0';
	return (res);
}

static char	*ft_cat_prevline(char *line, char **prev_line)
{
	if (!(*prev_line))
		return (line);
	line = ft_buffer_cat(line, *prev_line, ft_gnl_strlen(*prev_line));
	free(*prev_line);
	*prev_line = NULL;
	return (line);
}

static char	*ft_read_line(char *line, int fd, t_fdlist **list, t_fdlist **curr)
{
	ssize_t	count;
	char	*pos;
	char	buffer[BUFFER_SIZE];

	count = 1;
	pos = NULL;
	while (!pos && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
		{
			ft_delete_fd(fd, list);
			*curr = NULL;
			return (line);
		}
		line = ft_buffer_cat(line, buffer, (size_t)count);
		pos = ft_chr_lbreak(line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fdlist	*list = NULL;
	t_fdlist		*curr;
	char			*line;
	char			*pos;

	pos = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	curr = ft_get_fd(fd, &list);
	if (curr->prev_line)
	{
		line = ft_cat_prevline(line, &curr->prev_line);
		pos = ft_chr_lbreak(line);
		if (pos)
		{
			curr->prev_line = ft_prev_update(curr->prev_line, pos);
			return (line);
		}
	}
	line = ft_read_line(line, fd, &list, &curr);
	if (curr)
		curr->prev_line = ft_prev_update(curr->prev_line, ft_chr_lbreak(line));
	return (line);
}
