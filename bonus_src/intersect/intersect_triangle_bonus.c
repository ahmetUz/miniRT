/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:33:57 by auzun             #+#    #+#             */
/*   Updated: 2022/12/30 00:29:13 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_triangle_normal(t_vec *normal, t_obj *obj)
{
	ft_copy_vec(&obj->y_axis, normal);
	//ft_normalize_vec(normal);
}

static int	ft_get_triangle_hit(t_ray *ray, double t)
{
	t_vec	dist;

	if (t < 0 || t > ray->closest)
		return (0);
	ft_copy_vec(&ray->dir, &dist);
	ft_scale_vec(t, &dist);
	ft_add_vec(&ray->pos, &dist, &ray->hit);
	ray->closest = t;
	return (1);
}

static int	ft_is_inside(t_vec u, t_vec v, t_vec w, t_vec *hit)
{
	t_vec	v1;
	t_vec	v2;
	t_vec	tmp1;
	t_vec	tmp2;

	ft_sub_vec(&v, &u, &tmp1);
	ft_sub_vec(&w, &u, &tmp2);
	ft_cross_vec(&tmp1, &tmp2, &v1);
	ft_sub_vec(hit, &u, &tmp2);
	ft_cross_vec(&tmp1, &tmp2, &v2);
	if (ft_dot_product(&v1, &v2) < 0)
		return (0);
	return (1);
}

static double	ft_inter_plane(t_ray *ray, t_obj *obj)
{
	double	t;
	double	sc;
	t_vec	tmp;

	sc = ft_dot_product(&obj->y_axis, &ray->dir);
	if (sc == 0)
		return (-1);
	ft_sub_vec(&obj->som1, &ray->pos, &tmp);
	t = ft_dot_product(&obj->y_axis, &tmp) / sc;
	if (t > 0)
		return (t);
	return (-1);
}

int	ft_intersect_triangle(t_ray *ray, t_obj *obj)
{
	double	t;
	t_vec	hit;

	t = ft_inter_plane(ray, obj);
	if (t < 0)
		return (0);
	ft_copy_vec(&ray->dir, &hit);
	ft_scale_vec(t, &hit);
	ft_add_vec(&ray->pos, &hit, &hit);
	if (!ft_is_inside(obj->som1, obj->som3, obj->som2, &hit))
		return (0);
	if (!ft_is_inside(obj->som3, obj->som2, obj->som1, &hit))
		return (0);
	if (!ft_is_inside(obj->som2, obj->som1, obj->som3, &hit))
		return (0);
	return (ft_get_triangle_hit(ray, t));
}
