/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:58:55 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/27 23:41:34 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_copy_vec(t_vec *a, t_vec *res)
{
	res->x = a->x;
	res->y = a->y;
	res->z = a->z;
}

void	ft_normalize_vec(t_vec *a)
{
	ft_scale_vec(1 / ft_len_vec(a), a);
}

void	ft_get_hit_normal(t_ray *hit, t_obj *obj, t_vec *normal)
{
	if (obj->type == cylinder)
		ft_cylinder_normal(&hit->hit, normal, obj);
	else if (obj->type == cone)
		ft_cone_normal(&hit->hit, normal, obj);
	else if (obj->type == sphere)
		ft_sphere_normal(&hit->hit, normal, obj);
	else if (obj->type == triangle)
		ft_triangle_normal(normal, obj);
	else
		ft_plane_normal(normal, obj);
}
