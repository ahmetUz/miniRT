/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:12:12 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 11:16:48 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_clean_object(void *obj)
{
	t_obj	*object;

	object = (t_obj *)obj;
	if (object->texture.path)
		free(object->texture.path);
	free(obj);
}

int	ft_cleanup(t_env *env)
{
	if (env->cam)
		free(env->cam);
	ft_lstclear(&env->objs, ft_clean_object);
	ft_lstclear(&env->lights, free);
	return (0);
}

static void	ft_clean_textures(t_env *env)
{
	t_list	*list;

	list = env->imgs;
	while (list)
	{
		mlx_destroy_image(env->mlx, list->content);
		list = list->next;
	}
	ft_lstclear(&env->imgs, NULL);
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
	ft_clean_textures(env);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(EXIT_SUCCESS);
}
