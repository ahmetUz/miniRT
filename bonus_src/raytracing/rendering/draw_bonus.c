/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:32:02 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 13:42:09 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_draw(t_env *env, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = &env->img->addr[y * env->img->lsize + x * (env->img->bpp / 8)];
	*(int *)pixel = color;
}

unsigned int	ft_read_img(t_img *img, int x, int y)
{
	int				pixel;
	unsigned int	color;

	pixel = (y * img->lsize) + (x * img->bpp / 8);
	color = (img->addr[pixel] & 0xff);
	color |= (img->addr[pixel + 1] & 0xff) << 8;
	color |= (img->addr[pixel + 2] & 0xff) << 16;
	return (color);
}
