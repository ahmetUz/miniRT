/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:40:00 by auzun             #+#    #+#             */
/*   Updated: 2022/12/30 00:18:40 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	ft_check_triangle(char **args, int line_count)
{
	if (ft_args_len(args) != 7)
		return (ft_argcount_error(line_count, ft_args_len(args), 7));
	if (!ft_valid_coord(args[1]))
		return (ft_coord_error(line_count, args[1]));
	if (!ft_valid_coord(args[2]))
		return (ft_coord_error(line_count, args[2]));
	if (!ft_valid_coord(args[3]))
		return (ft_coord_error(line_count, args[3]));
	if (!ft_valid_color(args[4]))
		return (ft_color_error(line_count, args[4]));
	if (!ft_valid_reflect(args[5]))
		return (ft_reflect_error(line_count, args[5]));
	if (!ft_valid_perturbation(args[6]))
		return (ft_perturbation_error(line_count, args[6]));
	if (!ft_valid_texture(args[7]))
		return (ft_texture_error(line_count, args[7]));
	return (EXIT_SUCCESS);
}

static void	ft_init_triangle(t_obj *obj)
{
	t_vec	tmp1;
	t_vec	tmp2;

	ft_sub_vec(&obj->som2, &obj->som1, &tmp1);
	ft_sub_vec(&obj->som3, &obj->som1, &tmp2);
	ft_cross_vec(&tmp1, &tmp2, &obj->y_axis);
	ft_normalize_vec(&obj->y_axis);
}

int	ft_parse_triangle(t_env *env, char **args, int line_count)
{
	t_obj	*object;

	if (ft_check_triangle(args, line_count) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	object = (t_obj *)malloc(sizeof(t_obj));
	if (!object)
		return (EXIT_FAILURE);
	object->type = triangle;
	ft_parse_coord(args[1], &object->som1);
	ft_parse_coord(args[2], &object->som2);
	ft_parse_coord(args[3], &object->som3);
	ft_parse_color(args[4], &object->color);
	object->reflection = ft_atod(args[5]);
	object->perturbation = ft_parse_perturbation(args[6]);
	ft_init_triangle(object);
	ft_lstadd_front(&env->objs, ft_lstnew(object));
	return (ft_parse_texture(env, &object->texture, args[7]));
}
