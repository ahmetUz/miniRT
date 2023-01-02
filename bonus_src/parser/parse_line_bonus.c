/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:59:54 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/27 23:26:54 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	(*ft_get_parse_func(char *id))(t_env *env, char **args, int line)
{
	size_t	len;

	len = ft_strlen(id);
	if (len == 1)
	{
		if (!ft_strncmp(id, AMBIENT, len) || !ft_strncmp(id, POSLIGHT, len))
			return (ft_parse_light);
		if (!ft_strncmp(id, CAMERA, len))
			return (ft_parse_camera);
	}
	if (len != 2)
		return (NULL);
	if (!ft_strncmp(id, SPHERE, len))
		return (ft_parse_sphere);
	if (!ft_strncmp(id, PLANE, len))
		return (ft_parse_plane);
	if (!ft_strncmp(id, CYLINDER, len))
		return (ft_parse_cylinder);
	if (!ft_strncmp(id, CONE, len))
		return (ft_parse_cone);
	if (!ft_strncmp(id, TRIANGLE, len))
		return (ft_parse_triangle);
	return (NULL);
}

int	ft_parse_line(t_env *env, char *line, int line_count)
{
	int		(*parse_func)(t_env *, char **, int);
	int		status;
	char	**line_args;

	line = ft_strtrim(line, "\n");
	line_args = ft_split(line, ' ');
	if (!line_args[0])
	{
		ft_clear_tab(line_args);
		free(line);
		return (EXIT_SUCCESS);
	}
	parse_func = ft_get_parse_func(line_args[0]);
	if (!parse_func)
	{
		ft_identifier_error(line_args[0], line_count);
		ft_clear_tab(line_args);
		free(line);
		return (EXIT_FAILURE);
	}
	status = parse_func(env, line_args, line_count);
	ft_clear_tab(line_args);
	free(line);
	return (status);
}
