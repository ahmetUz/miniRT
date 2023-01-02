/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_mapping_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:57:52 by auzun             #+#    #+#             */
/*   Updated: 2022/12/29 22:33:16 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_map_sphere(t_obj *obj, t_vec *hit, double *u, double *v)
{
	double	theta;
	double	phi;
	t_vec	pos;

	ft_sub_vec(hit, &obj->pos, &pos);
	ft_normalize_vec(&pos);
	theta = atan2(pos.x, pos.z) + PI / 2;
	phi = acos(-1 * pos.y);
	*u = 1 - (theta / PI);
	*v = 1 - (phi / PI);
}

void	ft_map_plane(t_obj *obj, t_vec *hit, double *u, double *v)
{
	t_vec	pos;
	t_vec	tmp;
	double	dist;

	ft_sub_vec(hit, &obj->pos, &pos);
	dist = ft_dot_product(&obj->dir, &pos);
	ft_copy_vec(&obj->dir, &tmp);
	ft_scale_vec(dist, &tmp);
	ft_sub_vec(hit, &tmp, &tmp);
	*u = ft_dot_product(&tmp, &obj->x_axis) / 100.0;
	*v = ft_dot_product(&tmp, &obj->y_axis) / 100.0;
	while (*u > 1)
		*u -= 1;
	while (*u < 0)
		*u += 1;
	while (*v > 1)
		*v -= 1;
	while (*v < 0)
		*v += 1;
}

void	ft_map_cylinder(t_obj *obj, t_vec *hit, double *u, double *v)
{
	t_vec	pos;
	t_vec	tmp;
	double	theta;
	double	dist;

	ft_sub_vec(hit, &obj->pos, &pos);
	dist = ft_dot_product(&obj->dir, &pos);
	ft_copy_vec(&obj->dir, &tmp);
	ft_scale_vec(dist, &tmp);
	ft_sub_vec(hit, &tmp, &tmp);
	if (obj->dir.y != 0)
		theta = atan2(tmp.x, tmp.z) + PI / 2;
	else
		theta = atan2(tmp.y, tmp.z) + PI / 2;
	*u = theta;
	*v = dist / obj->height;
}

void	ft_map_cone(t_obj *obj, t_vec *hit, double *u, double *v)
{
	t_vec	pos;
	t_vec	tmp;
	double	theta;
	double	dist;

	ft_sub_vec(hit, &obj->pos, &pos);
	dist = ft_dot_product(&obj->dir, &pos);
	ft_copy_vec(&obj->dir, &tmp);
	ft_scale_vec(dist, &tmp);
	ft_sub_vec(hit, &tmp, &tmp);
	if (obj->dir.y != 0)
		theta = atan2(tmp.x, tmp.z) + PI / 2;
	else
		theta = atan2(tmp.y, tmp.z) + PI / 2;
	*u = theta;
	*v = dist / obj->height;
}

void	ft_map_triangle(t_obj *obj, t_vec *hit, double *u, double *v)
{
	t_vec	barycentric;

	ft_barycentric_coords(hit, obj, &barycentric);
	*u = barycentric.x;
	*v = barycentric.y;
}
