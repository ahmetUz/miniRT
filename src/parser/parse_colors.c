/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:43:51 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/19 16:26:44 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_parse_color(char *arg, t_vec *color)
{
	char	**args;

	args = ft_split(arg, ',');
	color->x = ft_atod(args[0]);
	color->y = ft_atod(args[1]);
	color->z = ft_atod(args[2]);
	ft_clear_tab(args);
}
