/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:04:28 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/24 10:56:04 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ft_init_window(t_env *env)
{
	env->window = mlx_new_window(env->mlx, WIDTH, HEIGHT, "miniRT");
	if (!env->window)
		return (EXIT_FAILURE);
	mlx_key_hook(env->window, ft_key_hook, env);
	mlx_loop_hook(env->mlx, ft_handle_nothing, env);
	mlx_hook(env->window, WINDOW_DESTROY, (1L << 0), ft_mlx_clean, env);
	return (EXIT_SUCCESS);
}

static int	ft_init_image(t_env *env)
{
	env->img = (t_img *)malloc(sizeof(t_img));
	if (!env->img)
		return (EXIT_FAILURE);
	env->img->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img->img)
		return (EXIT_FAILURE);
	env->img->addr = mlx_get_data_addr(env->img->img,
			&env->img->bpp, &env->img->lsize, &env->img->endian);
	return (EXIT_SUCCESS);
}

int	ft_init_mlx(t_env *env)
{
	env->img = NULL;
	env->mlx = mlx_init();
	if (!env->mlx)
		return (EXIT_FAILURE);
	if (ft_init_window(env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (ft_init_image(env));
}

void	ft_init_inter_point(t_inter *inter_point)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		inter_point->t[i] = INFINITY;
		inter_point->p[i].x = 0;
		inter_point->p[i].y = 0;
		inter_point->p[i].z = 0;
	}
	inter_point->hit = FALSE;
}

int	ft_init_env(t_env *env)
{
	env->cam = NULL;
	env->objs = NULL;
	env->lights = NULL;
	env->nb_obj = 0;
	env->nb_light = 0;
	return (EXIT_SUCCESS);
}
