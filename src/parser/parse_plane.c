/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:48:24 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 15:50:50 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_check_plane(char **args, int line_count)
{
	if (ft_args_len(args) != 3)
		return (ft_argcount_error(line_count, ft_args_len(args), 3));
	if (!ft_valid_coord(args[1]))
		return (ft_coord_error(line_count, args[1]));
	if (!ft_valid_dir(args[2]))
		return (ft_dir_error(line_count, args[2]));
	if (!ft_valid_color(args[3]))
		return (ft_color_error(line_count, args[3]));
	return (EXIT_SUCCESS);
}

int	ft_parse_plane(t_env *env, char **args, int line_count)
{
	t_obj	*object;

	if (ft_check_plane(args, line_count) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	object = (t_obj *)malloc(sizeof(t_obj));
	if (!object)
		return (EXIT_FAILURE);
	object->type = plane;
	ft_parse_coord(args[1], &object->pos);
	ft_parse_coord(args[2], &object->dir);
	ft_parse_color(args[3], &object->color);
	ft_normalize_vec(&object->dir);
	ft_lstadd_front(&env->objs, ft_lstnew(object));
	return (EXIT_SUCCESS);
}
