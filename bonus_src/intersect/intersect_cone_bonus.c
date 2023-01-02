/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:29:23 by auzun             #+#    #+#             */
/*   Updated: 2022/12/27 12:12:29 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

/*Check if the points of intersection are within the cap of the cone*/
void	ft_intersect_cone_caps(t_ray *ray, t_obj *obj, t_inter *inter_point)
{
	t_vec	caps_to_ray;
	t_vec	caps_points;
	t_vec	intersection;
	double	t;

	ft_get_cap(obj, &caps_points, 1);
	ft_sub_vec(&caps_points, &ray->pos, &caps_to_ray);
	t = ft_dot_product(&caps_to_ray, &obj->dir) / \
		ft_dot_product(&ray->dir, &obj->dir);
	ft_copy_vec(&ray->dir, &intersection);
	ft_scale_vec(t, &intersection);
	ft_add_vec(&ray->pos, &intersection, &intersection);
	if (t > 0 && ft_eucl_dist(&intersection, \
		&caps_points) <= obj->radius)
	{
		inter_point->t[2] = t;
		ft_copy_vec(&intersection, &inter_point->p[2]);
		inter_point->hit = TRUE;
	}
}

/*Check if the points of intersection are within the height of the cone*/
void	ft_intersect_cone_height(t_ray *ray, t_obj *obj,
	t_inter *inter_point, t_quad_vars var)
{
	t_vec	intersection;
	t_vec	tmp;
	double	dist;
	int		i;

	inter_point->t[0] = (-var.b - sqrt(var.delta)) / (2 * var.a);
	inter_point->t[1] = (-var.b + sqrt(var.delta)) / (2 * var.a);
	i = -1;
	while (++i < 2)
	{
		ft_copy_vec(&ray->dir, &tmp);
		ft_scale_vec(inter_point->t[i], &tmp);
		ft_add_vec(&ray->pos, &tmp, &intersection);
		ft_sub_vec(&intersection, &obj->pos, &tmp);
		dist = ft_dot_product(&tmp, &obj->dir);
		if (dist >= 0 && dist <= obj->height)
		{
			inter_point->p[i] = intersection;
			inter_point->hit = TRUE;
		}
		else
			inter_point->t[i] = INFINITY;
	}
}

int	ft_intersect_cone(t_ray *ray, t_obj *obj)
{
	t_inter			inter_point;
	t_quad_vars		var;
	double			m;
	t_vec			w;
	double			d[2];

	ft_normalize_vec(&obj->dir);
	m = (obj->radius * obj->radius) / (obj->height * obj->height);
	ft_sub_vec(&ray->pos, &obj->pos, &w);
	d[0] = ft_dot_product(&ray->dir, &obj->dir);
	d[1] = ft_dot_product(&w, &obj->dir);
	var.a = d[0] * d[0];
	var.a = ft_dot_product(&ray->dir, &ray->dir) - m * var.a - var.a;
	var.b = 2 * (ft_dot_product(&ray->dir, &w) - m * d[0] * d[1] - d[0] * d[1]);
	var.c = ft_dot_product(&w, &w) - m * (d[1] * d[1]) - (d[1] * d[1]);
	var.delta = (var.b * var.b) - 4 * var.a * var.c;
	if (var.delta < 0)
		return (0);
	ft_init_inter_point(&inter_point);
	ft_intersect_cone_caps(ray, obj, &inter_point);
	ft_intersect_cone_height(ray, obj, &inter_point, var);
	return (ft_get_cone_hit_point(ray, &inter_point));
}
