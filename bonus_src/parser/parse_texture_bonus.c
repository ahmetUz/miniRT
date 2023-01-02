/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:02:04 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/29 18:52:58 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_perturb_type	ft_parse_perturbation(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len == 4)
	{
		if (!ft_strncmp(arg, PNONE, 4))
			return (none);
		return (ring);
	}
	if (!ft_strncmp(arg, CHECKER, 7))
		return (checker);
	return (stripe);
}

int	ft_parse_texture(t_env *env, t_texture *texture, char *arg)
{
	if (ft_strlen(arg) == 4 && !ft_strncmp(arg, PNONE, 4))
	{
		texture->path = NULL;
		return (EXIT_SUCCESS);
	}
	texture->path = ft_strdup(arg);
	texture->img.img = mlx_xpm_file_to_image(env->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img.img)
		return (ft_xpm_error(arg));
	texture->img.addr = mlx_get_data_addr(texture->img.img, \
		&texture->img.bpp, &texture->img.lsize, &texture->img.endian);
	ft_lstadd_front(&env->imgs, ft_lstnew(texture->img.img));
	return (EXIT_SUCCESS);
}
