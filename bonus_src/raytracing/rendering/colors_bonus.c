/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:24:24 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 14:54:03 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	ft_clamp_rgb(t_vec *rgb)
{
	if (rgb->x > 255)
		rgb->x = 255;
	if (rgb->y > 255)
		rgb->y = 255;
	if (rgb->z > 255)
		rgb->z = 255;
}

unsigned int	ft_rgb_to_uint(t_vec *rgb)
{
	ft_clamp_rgb(rgb);
	return ((int)rgb->x << 16 | (int)rgb->y << 8 | (int)rgb->z);
}

void	ft_uint_to_rgb(unsigned int color, t_vec *rgb)
{
	rgb->x = (color >> 16) & 255;
	rgb->y = (color >> 8) & 255;
	rgb->z = color & 255;
}

void	ft_get_color(t_obj *obj, t_vec *hit, t_vec *rgb)
{
	unsigned int	obj_color;
	unsigned int	res_color;
	double			u;
	double			v;

	if (!ft_is_textured(obj, hit))
	{
		ft_copy_vec(&obj->color, rgb);
		return ;
	}
	ft_uv_map(obj, hit, &u, &v);
	if (!obj->texture.path)
		obj_color = ft_rgb_to_uint(&obj->color);
	else
		obj_color = ft_get_texture_color(&obj->texture, u, v);
	res_color = obj_color;
	if (obj->perturbation != none)
		res_color = ft_apply_perturb(u, v, obj_color, obj->perturbation);
	ft_uint_to_rgb(res_color, rgb);
}
