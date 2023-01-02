/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:15:08 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 15:58:10 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_parse_coord(char *arg, t_vec *vec)
{
	char	**coord;

	coord = ft_split(arg, ',');
	vec->x = ft_atod(coord[0]);
	vec->y = ft_atod(coord[1]);
	vec->z = ft_atod(coord[2]);
	ft_clear_tab(coord);
}
