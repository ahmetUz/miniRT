/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:31:08 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/26 16:27:42 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static double	ft_get_light_intensity(t_ray *hit, t_vec *dir, t_obj *obj)
{
	t_vec	normal;
	double	intensity;

	ft_get_hit_normal(hit, obj, &normal);
	intensity = ft_dot_product(&normal, dir);
	if (intensity < 0)
		return (0);
	intensity /= ft_len_vec(dir);
	if (intensity > 1)
		return (1);
	return (intensity);
}

static double	ft_get_specular(t_ray *ray, t_vec *dir, t_obj *obj)
{
	t_vec	r;
	t_vec	normal;
	t_vec	v;
	double	r_dot_v;

	ft_get_hit_normal(ray, obj, &normal);
	ft_copy_vec(&normal, &r);
	ft_scale_vec(2, &r);
	ft_scale_vec(ft_dot_product(&normal, dir), &r);
	ft_sub_vec(&r, dir, &r);
	ft_sub_vec(&ray->hit, &ray->pos, &v);
	ft_scale_vec(-1, &v);
	r_dot_v = ft_dot_product(&r, &v);
	if (r_dot_v <= 0)
		return (0);
	return (pow(r_dot_v / (ft_len_vec(&r) * ft_len_vec(&v)), 10));
}

static void	ft_apply_light(t_light *light, t_obj *obj, t_ray *ray, t_vec *scale)
{
	t_vec	dir;
	double	intensity;

	if (light->type == ambient)
		intensity = light->brightness;
	else
	{
		ft_sub_vec(&light->pos, &ray->hit, &dir);
		intensity = ft_get_light_intensity(ray, &dir, obj) * light->brightness;
		intensity += ft_get_specular(ray, &dir, obj) * light->brightness;
	}
	scale->x += light->color.x * intensity;
	scale->y += light->color.y * intensity;
	scale->z += light->color.z * intensity;
}

unsigned int	ft_apply_lights(t_env *env, t_obj *obj, t_ray *ray)
{
	t_list	*lights;
	t_vec	rgb;
	t_vec	intensity;

	lights = env->lights;
	intensity.x = 0;
	intensity.y = 0;
	intensity.z = 0;
	while (lights)
	{
		if (!ft_is_shadow(env, ray, lights->content))
			ft_apply_light(lights->content, obj, ray, &intensity);
		lights = lights->next;
	}
	ft_get_color(obj, &ray->hit, &rgb);
	rgb.x *= intensity.x;
	rgb.y *= intensity.y;
	rgb.z *= intensity.z;
	return (ft_rgb_to_uint(&rgb));
}
