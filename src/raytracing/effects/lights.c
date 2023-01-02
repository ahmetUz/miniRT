/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:31:08 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 11:21:22 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	ft_get_light_intensity(t_ray *hit, t_vec *dir, t_obj *obj)
{
	t_vec	normal;
	double	intensity;

	if (obj->type == cylinder)
		ft_cylinder_normal(&hit->hit, &normal, obj);
	else if (obj->type == sphere)
		ft_sphere_normal(&hit->hit, &normal, obj);
	else
		ft_plane_normal(&normal, obj);
	intensity = ft_dot_product(&normal, dir);
	if (intensity < 0)
		return (0);
	intensity /= ft_len_vec(dir);
	return (intensity);
}

static double	ft_apply_light(t_light *light, t_obj *obj, t_ray *ray)
{
	t_vec	dir;
	double	intensity;

	if (light->type == ambient)
		return (light->brightness);
	ft_sub_vec(&light->pos, &ray->hit, &dir);
	intensity = ft_get_light_intensity(ray, &dir, obj);
	intensity *= light->brightness;
	if (intensity >= 1)
		return (1);
	return (intensity);
}

unsigned int	ft_apply_lights(t_env *env, t_obj *obj, t_ray *ray)
{
	t_list	*lights;
	t_vec	rgb;
	double	intensity;

	lights = env->lights;
	intensity = 0;
	while (lights)
	{
		if (!ft_is_shadow(env, obj, ray, lights->content))
			intensity += ft_apply_light(lights->content, obj, ray);
		lights = lights->next;
	}
	if (intensity >= 1)
		intensity = 1;
	ft_copy_vec(&obj->color, &rgb);
	ft_scale_vec(intensity, &rgb);
	return (ft_rgb_to_uint(rgb));
}
