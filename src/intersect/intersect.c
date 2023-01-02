/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:25:10 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 11:04:48 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_get_hit_point(t_ray *ray, double a, double b, double d)
{
	double	t1;
	double	t2;
	double	t;
	t_vec	dist;

	t1 = (b + sqrt(d)) / a;
	t2 = (b - sqrt(d)) / a;
	if (t1 < 0)
		t = t2;
	else if (t2 < 0)
		t = t1;
	else if (t1 < t2)
		t = t1;
	else
		t = t2;
	if (t < 0 || t > ray->closest)
		return (0);
	ft_copy_vec(&ray->dir, &dist);
	ft_scale_vec(t, &dist);
	ft_add_vec(&ray->pos, &dist, &ray->hit);
	ray->closest = t;
	return (1);
}

int	ft_intersect(t_ray *ray, t_obj *obj)
{
	if (obj->type == sphere)
		return (ft_intersect_sphere(ray, obj));
	else if (obj->type == cylinder)
		return (ft_intersect_cylinder(ray, obj));
	else if (obj->type == plane)
		return (ft_intersect_plane(ray, obj));
	return (0);
}
