/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:55:02 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/22 11:06:41 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_check_light_exists(t_env *env, t_light_type type)
{
	t_list	*lights;

	lights = env->lights;
	while (lights)
	{
		if (((t_light *)lights->content)->type == type)
			return (1);
		lights = lights->next;
	}
	return (0);
}

static int	ft_parse_ambient(t_env *env, char **args, int line_count)
{
	t_light	*light;

	if (ft_check_light_exists(env, ambient))
		return (ft_extra_light_error(line_count, ambient));
	if (ft_args_len(args) != 2)
		return (ft_argcount_error(line_count, ft_args_len(args), 2));
	if (!ft_valid_double(args[1]))
		return (ft_double_error(line_count, args[1]));
	if (!ft_valid_color(args[2]))
		return (ft_color_error(line_count, args[2]));
	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (EXIT_FAILURE);
	light->type = ambient;
	light->brightness = ft_atod(args[1]);
	ft_lstadd_front(&env->lights, ft_lstnew(light));
	return (EXIT_SUCCESS);
}

static int	ft_parse_positional(t_env *env, char **args, int line_count)
{
	t_light	*light;

	if (ft_check_light_exists(env, positional))
		return (ft_extra_light_error(line_count, positional));
	if (ft_args_len(args) != 3)
		return (ft_argcount_error(line_count, ft_args_len(args), 3));
	if (!ft_valid_coord(args[1]))
		return (ft_coord_error(line_count, args[1]));
	if (!ft_valid_double(args[2]))
		return (ft_double_error(line_count, args[2]));
	if (!ft_valid_color(args[3]))
		return (ft_color_error(line_count, args[3]));
	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (EXIT_FAILURE);
	light->type = positional;
	ft_parse_coord(args[1], &light->pos);
	light->brightness = ft_atod(args[2]);
	ft_lstadd_front(&env->lights, ft_lstnew(light));
	return (EXIT_SUCCESS);
}

int	ft_parse_light(t_env *env, char **args, int line_count)
{
	size_t	len;

	len = ft_strlen(args[0]);
	if (!ft_strncmp(args[0], AMBIENT, len))
		return (ft_parse_ambient(env, args, line_count));
	if (!ft_strncmp(args[0], POSLIGHT, len))
		return (ft_parse_positional(env, args, line_count));
	return (EXIT_FAILURE);
}
