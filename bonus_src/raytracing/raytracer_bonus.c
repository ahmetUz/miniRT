/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:50:59 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/30 09:57:05 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

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

unsigned int	ft_launch_ray(t_env *env, t_ray *ray, int depth)
{
	t_list			*objs;
	t_obj			*closest;

	closest = NULL;
	objs = env->objs;
	while (objs)
	{
		if (ft_intersect(ray, (t_obj *)objs->content))
			closest = (t_obj *)objs->content;
		objs = objs->next;
	}
	if (!closest)
		return (0);
	if (depth >= DEPTH_MAX || closest->reflection <= 0)
		return (ft_apply_lights(env, closest, ray));
	return (ft_relaunch_ray(env, closest, ray, depth));
}

void	ft_raytracer(t_env *env)
{
	int				x;
	int				y;
	t_ray			ray;
	unsigned int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_init_ray(&ray, env->cam, x, y);
			color = ft_launch_ray(env, &ray, 0);
			ft_draw(env, x, y, color);
			++x;
		}
		if (y % (HEIGHT / 8) == 0)
			mlx_put_image_to_window(env->mlx, env->window, env->img->img, 0, 0);
		++y;
		if (y == 50)
			printf("moitier\n");

	}
	printf("ENDED\n");
	mlx_put_image_to_window(env->mlx, env->window, env->img->img, 0, 0);
}
