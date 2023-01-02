/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:50:43 by auzun             #+#    #+#             */
/*   Updated: 2022/12/27 14:05:26 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static unsigned int	ft_compute_reflection(t_env *env, t_obj *obj,
						t_ray *ray, int depth)
{
	t_vec	rev_dir;
	t_vec	normal;
	t_vec	tmp;

	ft_copy_vec(&ray->dir, &rev_dir);
	ft_scale_vec(-1, &rev_dir);
	ft_get_hit_normal(ray, obj, &normal);
	ft_copy_vec(&normal, &tmp);
	ft_scale_vec(2, &tmp);
	ft_scale_vec(ft_dot_product(&normal, &rev_dir), &tmp);
	ft_sub_vec(&tmp, &rev_dir, &ray->dir);
	ft_copy_vec(&ray->hit, &ray->pos);
	ft_copy_vec(&ray->dir, &tmp);
	ft_scale_vec(EPSILON, &tmp);
	ft_add_vec(&tmp, &ray->pos, &ray->pos);
	ray->closest = DBL_MAX;
	return (ft_launch_ray(env, ray, depth));
}

unsigned int	ft_relaunch_ray(t_env *env, t_obj *obj, t_ray *ray, int depth)
{
	unsigned int	local_color;
	unsigned int	reflect_color;
	t_vec			local_rgb;
	t_vec			reflect_rgb;

	local_color = ft_apply_lights(env, obj, ray);
	ft_uint_to_rgb(local_color, &local_rgb);
	ft_scale_vec(1 - obj->reflection, &local_rgb);
	reflect_color = ft_compute_reflection(env, obj, ray, depth + 1);
	ft_uint_to_rgb(reflect_color, &reflect_rgb);
	ft_scale_vec(obj->reflection, &reflect_rgb);
	ft_add_vec(&local_rgb, &reflect_rgb, &reflect_rgb);
	return (ft_rgb_to_uint(&reflect_rgb));
}
