/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:32:15 by auzun             #+#    #+#             */
/*   Updated: 2022/12/20 16:02:23 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_cross_vec(t_vec *a, t_vec *b, t_vec *res)
{
	res->x = (a->y * b->z) - (a->z * b->y);
	res->y = (a->z * b->x) - (a->x * b->z);
	res->z = (a->x * b->y) - (a->y * b->x);
}

double	ft_eucl_dist(t_vec *a, t_vec *b)
{
	t_vec	displacement;

	ft_sub_vec(a, b, &displacement);
	return (sqrt(ft_dot_product(&displacement, &displacement)));
}
