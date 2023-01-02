/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:47:22 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 16:06:28 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

double			ft_eucl_dist(t_vec *a, t_vec *b);
void			ft_scale_vec(double k, t_vec *res);
void			ft_add_vec(t_vec *a, t_vec *b, t_vec *res);
void			ft_sub_vec(t_vec *a, t_vec *b, t_vec *res);
void			ft_cross_vec(t_vec *a, t_vec *b, t_vec *res);

void			ft_normalize_vec(t_vec *a);
void			ft_copy_vec(t_vec *a, t_vec *res);

double			ft_len_vec(t_vec *a);
double			ft_dot_product(t_vec *a, t_vec *b);

#endif
