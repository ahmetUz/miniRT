/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:50:28 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 16:36:29 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static double	ft_color_stripes(double u)
{
	int	u2;

	u2 = floor(u * 10);
	if (u2 % 2 == 0)
		return (1);
	return (0.2);
}

static double	ft_color_rings(double v)
{
	int	v2;

	v2 = floor(v * 10);
	if (v2 % 2 == 0)
		return (1);
	return (0.2);
}

static double	ft_color_checker(double u, double v)
{
	int	u2;
	int	v2;

	u2 = floor(u * 10);
	v2 = floor(v * 10);
	if ((u2 + v2) % 2 == 0)
		return (1);
	return (0.2);
}

unsigned int	ft_apply_perturb(double u, double v, unsigned int color,
							t_perturb_type type)
{
	t_vec	rgb;
	double	scaling;

	ft_uint_to_rgb(color, &rgb);
	if (type == ring)
		scaling = ft_color_rings(v);
	else if (type == stripe)
		scaling = ft_color_stripes(u);
	else
		scaling = ft_color_checker(u, v);
	ft_scale_vec(scaling, &rgb);
	return (ft_rgb_to_uint(&rgb));
}
