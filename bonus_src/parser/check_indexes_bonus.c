/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_indexes_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:54:20 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/27 14:03:20 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_valid_reflect(char *arg)
{
	double	value;

	if (!ft_valid_double(arg))
		return (0);
	value = ft_atod(arg);
	return (value >= 0 && value <= 1);
}
