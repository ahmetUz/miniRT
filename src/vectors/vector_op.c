/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:22:44 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/17 05:32:34 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_add_vec(t_vec *a, t_vec *b, t_vec *res)
{
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
}

void	ft_sub_vec(t_vec *a, t_vec *b, t_vec *res)
{
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
}

void	ft_scale_vec(double k, t_vec *res)
{
	res->x *= k;
	res->y *= k;
	res->z *= k;
}

double	ft_dot_product(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

double	ft_len_vec(t_vec *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}
