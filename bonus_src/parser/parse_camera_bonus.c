/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:09:16 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 13:42:03 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	ft_init_viewport(t_cam *cam)
{
	t_vec	u;
	t_vec	v;

	cam->width = 2 * tan(cam->fov * PI / 360.0);
	cam->height = cam->width * (HEIGHT / (double)WIDTH);
	ft_copy_vec(&cam->dir, &cam->viewport_dir);
	ft_scale_vec(-1, &cam->viewport_dir);
	ft_cross_vec(&cam->up, &cam->viewport_dir, &cam->viewport_right);
	ft_normalize_vec(&cam->viewport_right);
	ft_cross_vec(&cam->viewport_dir, &cam->viewport_right, &cam->viewport_up);
	ft_normalize_vec(&cam->viewport_up);
	ft_add_vec(&cam->pos, &cam->dir, &cam->viewport_origin);
	ft_copy_vec(&cam->viewport_up, &v);
	ft_copy_vec(&cam->viewport_right, &u);
	ft_scale_vec(cam->width / 2.0, &u);
	ft_scale_vec(cam->height / 2.0, &v);
	ft_sub_vec(&cam->viewport_origin, &v, &cam->viewport_origin);
	ft_sub_vec(&cam->viewport_origin, &u, &cam->viewport_origin);
}

static void	ft_init_camera(t_cam *cam)
{
	t_vec	tmp;
	t_vec	right;

	ft_normalize_vec(&cam->dir);
	tmp.z = 0;
	tmp.y = 0;
	tmp.x = 0;
	if (cam->dir.y == 1)
		tmp.x = 1;
	else if (cam->dir.y == -1)
		tmp.x = -1;
	else
		tmp.y = -1;
	ft_cross_vec(&tmp, &cam->dir, &right);
	ft_cross_vec(&cam->dir, &right, &cam->up);
	ft_normalize_vec(&cam->up);
	ft_init_viewport(cam);
}

int	ft_parse_camera(t_env *env, char **args, int line_count)
{
	if (env->cam)
		return (ft_extra_cam_error(line_count));
	if (ft_args_len(args) != 3)
		return (ft_argcount_error(line_count, ft_args_len(args), 3));
	if (!ft_valid_coord(args[1]))
		return (ft_coord_error(line_count, args[1]));
	if (!ft_valid_dir(args[2]))
		return (ft_dir_error(line_count, args[2]));
	if (!ft_valid_double(args[3]))
		return (ft_double_error(line_count, args[3]));
	if (!ft_valid_fov(args[3]))
		return (ft_fov_error(line_count, args[3]));
	env->cam = (t_cam *)malloc(sizeof(t_cam));
	if (!env->cam)
		return (EXIT_FAILURE);
	ft_parse_coord(args[1], &env->cam->pos);
	ft_parse_coord(args[2], &env->cam->dir);
	env->cam->fov = ft_atod(args[3]);
	ft_init_camera(env->cam);
	return (EXIT_SUCCESS);
}
