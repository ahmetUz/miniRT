/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:55:50 by auzun             #+#    #+#             */
/*   Updated: 2022/12/27 14:04:22 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_get_cone_hit_point(t_ray *ray, t_inter *inter_point)
{
	int		i;
	double	t;
	t_vec	closest_hit;

	if (inter_point->hit == FALSE)
		return (0);
	i = -1;
	t = INFINITY;
	while (++i < 3)
	{
		if (inter_point->t[i] > 0 && inter_point->t[i] < t)
		{
			t = inter_point->t[i];
			closest_hit = inter_point->p[i];
		}
	}
	if (t < 0 || t > ray->closest)
		return (0);
	ft_copy_vec(&closest_hit, &ray->hit);
	ray->closest = t;
	return (1);
}

int	ft_cone_cap_normal(t_vec *hit, t_vec *normal, t_obj *obj)
{
	t_vec	point;
	double	dist;
	double	radius;

	ft_sub_vec(hit, &obj->pos, &point);
	dist = ft_dot_product(&point, &obj->dir);
	radius = (dist / obj->height) * obj->radius;
	if (radius > obj->radius - EPSILON)
	{
		ft_copy_vec(&obj->dir, normal);
		return (1);
	}
	return (0);
}

void	ft_cone_normal(t_vec *hit, t_vec *normal, t_obj *obj)
{
	t_vec	point;
	t_vec	dist_pt;
	double	t;

	if (ft_cone_cap_normal(hit, normal, obj))
		return ;
	ft_sub_vec(hit, &obj->pos, &point);
	t = ft_dot_product(&point, &obj->dir);
	ft_copy_vec(&obj->dir, &dist_pt);
	ft_scale_vec(t, &dist_pt);
	ft_sub_vec(&point, &dist_pt, normal);
	ft_normalize_vec(normal);
}
