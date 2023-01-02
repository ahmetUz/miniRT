/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:34:15 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 16:38:30 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	ft_check_cylinder(char **args, int line_count)
{
	if (ft_args_len(args) != 8)
		return (ft_argcount_error(line_count, ft_args_len(args), 8));
	if (!ft_valid_coord(args[1]))
		return (ft_coord_error(line_count, args[1]));
	if (!ft_valid_dir(args[2]))
		return (ft_dir_error(line_count, args[2]));
	if (!ft_valid_double(args[3]))
		return (ft_double_error(line_count, args[3]));
	if (!ft_valid_numarg(args[3]))
		return (ft_numarg_error(line_count, args[3]));
	if (!ft_valid_double(args[4]))
		return (ft_double_error(line_count, args[4]));
	if (!ft_valid_numarg(args[4]))
		return (ft_numarg_error(line_count, args[4]));
	if (!ft_valid_color(args[5]))
		return (ft_color_error(line_count, args[5]));
	if (!ft_valid_reflect(args[6]))
		return (ft_reflect_error(line_count, args[6]));
	if (!ft_valid_perturbation(args[7]))
		return (ft_perturbation_error(line_count, args[7]));
	if (!ft_valid_texture(args[8]))
		return (ft_texture_error(line_count, args[8]));
	return (EXIT_SUCCESS);
}

int	ft_parse_cylinder(t_env *env, char **args, int line_count)
{
	t_obj	*object;

	if (ft_check_cylinder(args, line_count) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	object = (t_obj *)malloc(sizeof(t_obj));
	if (!object)
		return (EXIT_FAILURE);
	object->type = cylinder;
	ft_parse_coord(args[1], &object->pos);
	ft_parse_coord(args[2], &object->dir);
	object->radius = ft_atod(args[3]) / 2.0;
	object->height = ft_atod(args[4]);
	object->reflection = ft_atod(args[6]);
	object->perturbation = ft_parse_perturbation(args[7]);
	ft_parse_color(args[5], &object->color);
	ft_normalize_vec(&object->dir);
	ft_lstadd_front(&env->objs, ft_lstnew(object));
	return (ft_parse_texture(env, &object->texture, args[8]));
}
