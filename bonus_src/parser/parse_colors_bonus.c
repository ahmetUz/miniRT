/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:43:51 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 13:42:05 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_parse_color(char *arg, t_vec *color)
{
	char	**args;

	args = ft_split(arg, ',');
	color->x = ft_atod(args[0]);
	color->y = ft_atod(args[1]);
	color->z = ft_atod(args[2]);
	ft_clear_tab(args);
}
