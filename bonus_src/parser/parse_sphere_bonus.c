/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:45:04 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 14:56:08 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	ft_check_sphere(char **args, int line_count)
{
	if (ft_args_len(args) != 6)
		return (ft_argcount_error(line_count, ft_args_len(args), 6));
	if (!ft_valid_coord(args[1]))
		return (ft_coord_error(line_count, args[1]));
	if (!ft_valid_double(args[2]))
		return (ft_double_error(line_count, args[2]));
	if (!ft_valid_numarg(args[2]))
		return (ft_numarg_error(line_count, args[2]));
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

int	ft_parse_sphere(t_env *env, char **args, int line_count)
{
	t_obj	*object;

	if (ft_check_sphere(args, line_count) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	object = (t_obj *)malloc(sizeof(t_obj));
	if (!object)
		return (EXIT_FAILURE);
	object->type = sphere;
	ft_parse_coord(args[1], &object->pos);
	object->radius = ft_atod(args[2]) / 2.0;
	ft_parse_color(args[3], &object->color);
	object->reflection = ft_atod(args[4]);
	object->perturbation = ft_parse_perturbation(args[5]);
	ft_lstadd_front(&env->objs, ft_lstnew(object));
	return (ft_parse_texture(env, &object->texture, args[6]));
}
