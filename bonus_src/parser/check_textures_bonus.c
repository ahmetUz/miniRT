/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:47:43 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 14:36:44 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_valid_perturbation(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len != 4 && len != 7)
		return (0);
	if (len == 4)
		return (!ft_strncmp(arg, PNONE, 4) || !ft_strncmp(arg, RING, 4));
	return (!ft_strncmp(arg, STRIPE, 7) || !ft_strncmp(arg, CHECKER, 7));
}

static int	ft_check_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	return (!ft_strncmp(&filename[len - 4], ".xpm", 4));
}

int	ft_valid_texture(char *arg)
{
	int		fd;
	char	buf;

	if (ft_strlen(arg) == 4 && !ft_strncmp(arg, PNONE, 4))
		return (1);
	if (!ft_check_filename(arg))
		return (0);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, &buf, 0) < 0)
		return (0);
	close(fd);
	return (1);
}
