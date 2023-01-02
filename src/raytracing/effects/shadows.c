/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:31:03 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/14 15:56:55 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_is_shadow(t_env *env, t_obj *obj, t_ray *ray, t_light *light)
{
	t_list	*objs;
	t_ray	light_ray;

	(void)obj;
	if (light->type == ambient)
		return (0);
	ft_copy_vec(&ray->hit, &light_ray.pos);
	ft_sub_vec(&light->pos, &ray->hit, &light_ray.dir);
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
