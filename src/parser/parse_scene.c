/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:04:15 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/19 16:52:15 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_check_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len <= 3)
		return (0);
	return (!ft_strncmp(&filename[len - 3], ".rt", 3));
}

static void	ft_close_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static int	ft_read_scene(t_env *env, int fd)
{
	int		line_count;
	int		status;
	char	*line;

	line_count = 1;
	line = get_next_line(fd);
	status = EXIT_SUCCESS;
	while (line)
	{
		if (line[0] && line[0] != '\n')
			status = ft_parse_line(env, line, line_count);
		free(line);
		if (status != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		++line_count;
		line = get_next_line(fd);
	}
	if (!env->cam)
		return (ft_missing_cam_error());
	return (EXIT_SUCCESS);
}

int	ft_parse_scene(t_env *env, char *filename)
{
	int		fd;
	int		status;
	char	buf;

	if (!ft_check_filename(filename))
		return (ft_filename_error(filename));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_open_error(filename));
	if (read(fd, &buf, 0) < 0)
		return (ft_read_error(filename));
	status = ft_read_scene(env, fd);
	ft_close_file(fd);
	return (status);
}
