/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:41 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/12 13:24:04 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_key_hook(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		ft_mlx_clean(env);
	return (0);
}

int	ft_handle_nothing(t_env *env)
{
	if (!env)
		return (0);
	return (1);
}
