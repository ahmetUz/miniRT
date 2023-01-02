/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:58:26 by auzun             #+#    #+#             */
/*   Updated: 2022/12/24 10:57:53 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_get_cylinder_hit_point(t_ray *ray, t_inter *inter_point)
{
	int		i;
	double	t;
	t_vec	closest_hit;

	if (inter_point->hit == FALSE)
		return (0);
	i = -1;
	t = INFINITY;
	while (++i < 4)
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

void	ft_get_cap(t_obj *obj, t_vec *res, int get_top)
{
	t_vec	tmp;

	ft_copy_vec(&obj->dir, &tmp);
	if (get_top)
		ft_scale_vec(obj->height, &tmp);
	else
		ft_scale_vec(0, &tmp);
	ft_add_vec(&obj->pos, &tmp, res);
}

int	ft_cylinder_cap_normal(t_vec *hit, t_vec *normal, t_obj *obj)
{
	t_vec	point;

	ft_get_cap(obj, &point, 1);
	ft_sub_vec(hit, &point, &point);
	if (ft_len_vec(&point) < obj->radius)
	{
		ft_copy_vec(&obj->dir, normal);
		return (1);
	}
	ft_get_cap(obj, &point, 0);
	ft_sub_vec(hit, &point, &point);
	if (ft_len_vec(&point) < obj->radius)
	{
		ft_copy_vec(&obj->dir, normal);
		ft_scale_vec(-1, normal);
		return (1);
	}
	return (0);
}

void	ft_cylinder_normal(t_vec *hit, t_vec *normal, t_obj *obj)
{
	double	t;
	t_vec	pt;
	t_vec	dist_pt;
	t_vec	tmp;

	if (ft_cylinder_cap_normal(hit, normal, obj))
		return ;
	ft_sub_vec(hit, &obj->pos, &dist_pt);
	t = ft_dot_product(&dist_pt, &obj->dir);
	ft_copy_vec(&obj->dir, &tmp);
	ft_scale_vec(t, &tmp);
	ft_add_vec(&obj->pos, &tmp, &pt);
	ft_sub_vec(hit, &pt, normal);
	ft_normalize_vec(normal);
}
