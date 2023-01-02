/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:41 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 13:40:41 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

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
