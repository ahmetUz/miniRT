/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:48:24 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 14:56:22 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	ft_check_plane(char **args, int line_count)
{
	if (ft_args_len(args) != 6)
		return (ft_argcount_error(line_count, ft_args_len(args), 6));
	if (!ft_valid_coord(args[1]))
		return (ft_coord_error(line_count, args[1]));
	if (!ft_valid_dir(args[2]))
		return (ft_dir_error(line_count, args[2]));
	if (!ft_valid_color(args[3]))
		return (ft_color_error(line_count, args[3]));
	if (!ft_valid_reflect(args[4]))
		return (ft_reflect_error(line_count, args[4]));
	if (!ft_valid_perturbation(args[5]))
		return (ft_perturbation_error(line_count, args[5]));
	if (!ft_valid_texture(args[6]))
		return (ft_texture_error(line_count, args[6]));
	return (EXIT_SUCCESS);
}

static void	ft_init_plane(t_obj *obj)
{
	t_vec	tmp;

	tmp.z = 0;
	tmp.y = 0;
	tmp.x = 0;
	if (obj->dir.y == 1)
		tmp.x = 1;
	else if (obj->dir.y == -1)
		tmp.x = -1;
	else
		tmp.y = -1;
	ft_cross_vec(&obj->dir, &tmp, &obj->x_axis);
	ft_cross_vec(&obj->x_axis, &obj->dir, &obj->y_axis);
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
	object->reflection = ft_atod(args[4]);
	object->perturbation = ft_parse_perturbation(args[5]);
	ft_normalize_vec(&object->dir);
	ft_init_plane(object);
	ft_lstadd_front(&env->objs, ft_lstnew(object));
	return (ft_parse_texture(env, &object->texture, args[6]));
}
