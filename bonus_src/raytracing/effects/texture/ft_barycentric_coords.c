/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_barycentric_coords.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:05:03 by auzun             #+#    #+#             */
/*   Updated: 2022/12/29 19:07:57 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_barycentric_coords(t_vec *p, t_obj *obj, t_vec *barycentric)
{
	t_vec	v[3];
	double	dot_v[5];
	double	inv_denom;

	ft_sub_vec(&obj->som2, &obj->som1, &v[0]);
	ft_sub_vec(&obj->som3, &obj->som1, &v[1]);
	ft_sub_vec(p, &obj->som1, &v[2]);
	dot_v[0] = ft_dot_product(&v[0], &v[0]);
	dot_v[1] = ft_dot_product(&v[0], &v[1]);
	dot_v[2] = ft_dot_product(&v[1], &v[1]);
	dot_v[3] = ft_dot_product(&v[2], &v[0]);
	dot_v[4] = ft_dot_product(&v[2], &v[1]);
	inv_denom = 1.0 / (dot_v[0] * dot_v[2] - dot_v[1] * dot_v[1]);
	barycentric->y = (dot_v[2] * dot_v[3] - dot_v[1] * dot_v[4]) * inv_denom;
	barycentric->z = (dot_v[0] * dot_v[4] - dot_v[1] * dot_v[3]) * inv_denom;
	barycentric->x = 1.0 - barycentric->y - barycentric->z;
}
