/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:12:21 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/29 19:05:36 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_uv_map(t_obj *obj, t_vec *hit, double *u, double *v)
{
	if (obj->type == sphere)
		ft_map_sphere(obj, hit, u, v);
	else if (obj->type == cone)
		ft_map_cone(obj, hit, u, v);
	else if (obj->type == cylinder)
		ft_map_cylinder(obj, hit, u, v);
	else if (obj->type == triangle)
		ft_map_triangle(obj, hit, u, v);
	else
		ft_map_plane(obj, hit, u, v);
}
