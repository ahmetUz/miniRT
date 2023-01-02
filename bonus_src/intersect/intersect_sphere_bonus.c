/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:37:23 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 13:41:39 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_sphere_normal(t_vec *hit, t_vec *normal, t_obj *obj)
{
	ft_copy_vec(hit, normal);
	ft_sub_vec(normal, &obj->pos, normal);
	ft_normalize_vec(normal);
}

int	ft_intersect_sphere(t_ray *ray, t_obj *obj)
{
	t_vec		origin;
	t_quad_vars	var;

	ft_sub_vec(&ray->pos, &obj->pos, &origin);
	var.a = ft_dot_product(&ray->dir, &ray->dir);
	var.b = 2 * ft_dot_product(&origin, &ray->dir);
	var.c = ft_dot_product(&origin, &origin) - obj->radius * obj->radius;
	var.delta = (var.b * var.b) - (4 * var.a * var.c);
	if (var.delta < 0)
		return (0);
	return (ft_get_hit_point(ray, 2 * var.a, -var.b, var.delta));
}
