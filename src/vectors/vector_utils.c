/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:58:55 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/16 07:20:19 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_copy_vec(t_vec *a, t_vec *res)
{
	res->x = a->x;
	res->y = a->y;
	res->z = a->z;
}

void	ft_normalize_vec(t_vec *a)
{
	ft_scale_vec(1 / ft_len_vec(a), a);
}
