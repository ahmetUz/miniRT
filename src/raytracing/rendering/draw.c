/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:32:02 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/12 14:57:56 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_draw(t_env *env, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = &env->img->addr[y * env->img->lsize + x * (env->img->bpp / 8)];
	*(int *)pixel = color;
}
