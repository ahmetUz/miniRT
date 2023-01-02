/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:58:30 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/19 10:06:08 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(char	*s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

static char	*ft_buffer_crash(char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

char	*ft_buffer_cat(char *dest, char *buffer, size_t buffer_size)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	tmp = dest;
	len = ft_gnl_strlen(dest);
	dest = (char *)malloc(sizeof(char) * (len + buffer_size + 1));
	if (!dest)
		return (ft_buffer_crash(tmp));
	i = 0;
	while (i < len)
	{
		dest[i] = tmp[i];
		++i;
	}
	i = 0;
	while (i < buffer_size)
	{
		dest[i + len] = buffer[i];
		++i;
	}
	dest[len + buffer_size] = '\0';
	if (tmp)
		free(tmp);
	return (dest);
}

t_fdlist	*ft_get_fd(int fd, t_fdlist **list)
{
	if (!(*list))
	{
		*list = (t_fdlist *)malloc(sizeof(t_fdlist));
		if (!list)
			return (NULL);
		(*list)->fd = fd;
		(*list)->prev_line = NULL;
		(*list)->next = NULL;
		return (*list);
	}
	if ((*list)->fd == fd)
		return (*list);
	return (ft_get_fd(fd, &(*list)->next));
}

void	ft_delete_fd(int fd, t_fdlist **list)
{
	t_fdlist	*tmp;

	if (!(*list))
		return ;
	if ((*list)->fd == fd)
	{
		tmp = (*list)->next;
		if ((*list)->prev_line)
			free((*list)->prev_line);
		free(*list);
		*list = tmp;
		return ;
	}
	ft_delete_fd(fd, &(*list)->next);
}
