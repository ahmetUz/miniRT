/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:12:12 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 11:37:59 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_cleanup(t_env *env)
{
	if (env->cam)
		free(env->cam);
	ft_lstclear(&env->objs, free);
	ft_lstclear(&env->lights, free);
	return (0);
}

int	ft_mlx_clean(t_env *env)
{
	ft_cleanup(env);
	if (!env->mlx)
		return (0);
	if (env->window)
		mlx_destroy_window(env->mlx, env->window);
	if (env->img)
	{
		if (env->img->img)
			mlx_destroy_image(env->mlx, env->img->img);
		free(env->img);
	}
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(EXIT_SUCCESS);
}
