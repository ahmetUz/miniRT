/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:58:18 by auzun             #+#    #+#             */
/*   Updated: 2022/12/23 09:33:08 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_plane_normal(t_vec *normal, t_obj *obj)
{
	ft_copy_vec(&obj->dir, normal);
}

static int	ft_get_plane_hit(t_ray *ray, double t)
{
	t_vec	dist;

	ft_copy_vec(&ray->dir, &dist);
	ft_scale_vec(t, &dist);
	ft_add_vec(&ray->pos, &dist, &ray->hit);
	ray->closest = t;
	return (1);
}

int	ft_intersect_plane(t_ray *ray, t_obj *obj)
{
	t_vec	origin;
	double	denom;
	double	t;

	ft_sub_vec(&obj->pos, &ray->pos, &origin);
	denom = ft_dot_product(&ray->dir, &obj->dir);
	if (fabs(denom) > EPSILON)
	{
		t = ft_dot_product(&origin, &obj->dir) / denom;
		if (t >= EPSILON && t < ray->closest)
			return (ft_get_plane_hit(ray, t));
	}
	return (0);
}
