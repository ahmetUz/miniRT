/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coord_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:15:08 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 13:42:08 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	ft_parse_coord(char *arg, t_vec *vec)
{
	char	**coord;

	coord = ft_split(arg, ',');
	vec->x = ft_atod(coord[0]);
	vec->y = ft_atod(coord[1]);
	vec->z = ft_atod(coord[2]);
	ft_clear_tab(coord);
}
