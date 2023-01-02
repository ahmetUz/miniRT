/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:31:03 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/26 17:08:32 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_is_shadow(t_env *env, t_ray *ray, t_light *light)
{
	t_list	*objs;
	t_ray	light_ray;
	t_vec	dir;

	if (light->type == ambient)
		return (0);
	ft_copy_vec(&ray->hit, &light_ray.pos);
	ft_sub_vec(&light->pos, &ray->hit, &light_ray.dir);
	ft_copy_vec(&light_ray.dir, &dir);
	ft_scale_vec(EPSILON, &dir);
	ft_add_vec(&dir, &light_ray.pos, &light_ray.pos);
	light_ray.closest = DBL_MAX;
	objs = env->objs;
	while (objs)
	{
		if (ft_intersect(&light_ray, objs->content))
		{
			if (light_ray.closest > EPSILON && light_ray.closest < 1)
				return (1);
			light_ray.closest = DBL_MAX;
		}
		objs = objs->next;
	}
	return (0);
}
