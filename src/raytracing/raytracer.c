/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:50:59 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 13:54:45 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_init_ray(t_ray *ray, t_cam *cam, int x, int y)
{
	t_vec	up;
	t_vec	right;
	t_vec	viewport;

	ft_copy_vec(&cam->pos, &ray->pos);
	ft_copy_vec(&cam->viewport_up, &up);
	ft_copy_vec(&cam->viewport_right, &right);
	ft_scale_vec(x * (cam->width / (double)WIDTH), &right);
	ft_scale_vec(y * (cam->height / (double)HEIGHT), &up);
	ft_add_vec(&right, &up, &viewport);
	ft_add_vec(&viewport, &cam->viewport_origin, &ray->dir);
	ft_sub_vec(&ray->dir, &cam->pos, &ray->dir);
	ft_normalize_vec(&ray->dir);
	ray->closest = DBL_MAX;
}

static void	ft_launch_ray(t_env *env, int x, int y)
{
	unsigned int	color;
	t_list			*objs;
	t_obj			*closest;
	t_ray			ray;

	closest = NULL;
	ft_init_ray(&ray, env->cam, x, y);
	objs = env->objs;
	while (objs)
	{
		if (ft_intersect(&ray, (t_obj *)objs->content))
			closest = (t_obj *)objs->content;
		objs = objs->next;
	}
	if (closest)
		color = ft_apply_lights(env, closest, &ray);
	else
		color = 0;
	ft_draw(env, x, y, color);
}

void	ft_raytracer(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_launch_ray(env, x, y);
			++x;
		}
		if (y % (HEIGHT / 8) == 0)
			mlx_put_image_to_window(env->mlx, env->window, env->img->img, 0, 0);
		++y;
	}
	mlx_put_image_to_window(env->mlx, env->window, env->img->img, 0, 0);
}
