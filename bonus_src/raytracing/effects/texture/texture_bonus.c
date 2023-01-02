/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:39:20 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/29 18:53:29 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_is_textured(t_obj *obj, t_vec *hit)
{
	t_vec	normal;

	if (obj->type == cylinder && ft_cylinder_cap_normal(hit, &normal, obj))
		return (0);
	return (obj->perturbation != none || obj->texture.path != NULL);
}

unsigned int	ft_get_texture_color(t_texture *texture, double u, double v)
{
	int	x;
	int	y;

	x = (int)floor(u * (texture->width - 1));
	y = (int)floor(v * (texture->height - 1));
	return (ft_read_img(&texture->img, x, y));
}
