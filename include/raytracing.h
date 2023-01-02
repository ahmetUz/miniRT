/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:58:26 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/24 10:57:47 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "objects.h"

typedef struct s_ray
{
	t_vec	pos;
	t_vec	dir;
	t_vec	hit;
	double	closest;
}			t_ray;

typedef struct s_cam
{
	t_vec	pos;
	t_vec	dir;
	t_vec	up;
	t_vec	viewport_up;
	t_vec	viewport_right;
	t_vec	viewport_dir;
	t_vec	viewport_origin;
	double	fov;
	double	width;
	double	height;
}			t_cam;

typedef struct s_quad_vars
{
	double	a;
	double	b;
	double	c;
	double	delta;
}			t_quad_vars;

void			ft_init_inter_point(t_inter *inter_point);

int				ft_intersect(t_ray *ray, t_obj *obj);
int				ft_intersect_sphere(t_ray *ray, t_obj *obj);
int				ft_intersect_cylinder(t_ray *ray, t_obj *obj);
int				ft_intersect_plane(t_ray *ray, t_obj *obj);

int				ft_get_cylinder_hit_point(t_ray *ray, t_inter *inter_point);
int				ft_get_hit_point(t_ray *ray, double a, double b, double d);

void			ft_get_cap(t_obj *obj, t_vec *res, int get_top);
int				ft_cylinder_cap_normal(t_vec *hit, t_vec *normal, t_obj *obj);
void			ft_cylinder_normal(t_vec *hit, t_vec *normal, t_obj *obj);
void			ft_get_cap(t_obj *obj, t_vec *res, int get_top);
void			ft_plane_normal(t_vec *normal, t_obj *obj);
void			ft_sphere_normal(t_vec *hit, t_vec *normal, t_obj *obj);

#endif
