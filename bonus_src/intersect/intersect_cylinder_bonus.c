/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:01:56 by auzun             #+#    #+#             */
/*   Updated: 2022/12/24 11:01:34 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

/*Check if the points of intersection are within the caps of the cylinder*/
void	ft_intersect_cylinder_caps(t_ray *ray, t_obj *obj, t_inter *inter_point)
{
	t_vec	caps_to_ray;
	t_vec	caps_points[2];
	t_vec	intersection;
	double	t;
	int		i;

	ft_get_cap(obj, &caps_points[0], 1);
	ft_get_cap(obj, &caps_points[1], 0);
	i = -1;
	while (++i < 2)
	{
		ft_sub_vec(&caps_points[i], &ray->pos, &caps_to_ray);
		t = ft_dot_product(&caps_to_ray, &obj->dir) / \
			ft_dot_product(&ray->dir, &obj->dir);
		ft_copy_vec(&ray->dir, &intersection);
		ft_scale_vec(t, &intersection);
		ft_add_vec(&ray->pos, &intersection, &intersection);
		if (t > 0 && ft_eucl_dist(&intersection, \
			&caps_points[i]) <= obj->radius)
		{
			inter_point->t[i + 2] = t;
			ft_copy_vec(&intersection, &inter_point->p[i + 2]);
			inter_point->hit = TRUE;
		}
	}
}

/*Check if the points of intersection are within the height of the cylinder*/
void	ft_intersect_cylinder_height(t_ray *ray, t_obj *obj,
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

int	ft_intersect_cylinder(t_ray *ray, t_obj *obj)
{
	t_vec		c_to_o;
	t_vec		tmp;
	t_ray		new_ray;
	t_inter		inter_point;
	t_quad_vars	var;

	ft_copy_vec(&ray->pos, &new_ray.pos);
	ft_cross_vec(&ray->dir, &obj->dir, &new_ray.dir);
	ft_sub_vec(&ray->pos, &obj->pos, &tmp);
	ft_cross_vec(&tmp, &obj->dir, &c_to_o);
	var.a = ft_dot_product(&new_ray.dir, &new_ray.dir);
	var.b = 2 * ft_dot_product(&new_ray.dir, &c_to_o);
	var.c = ft_dot_product(&c_to_o, &c_to_o) - obj->radius * obj->radius;
	var.delta = (var.b * var.b) - 4 * var.a * var.c;
	if (var.delta < 0)
		return (0);
	ft_init_inter_point(&inter_point);
	ft_intersect_cylinder_caps(ray, obj, &inter_point);
	ft_intersect_cylinder_height(ray, obj, &inter_point, var);
	return (ft_get_cylinder_hit_point(ray, &inter_point));
}
