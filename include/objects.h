/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:56:47 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 16:04:13 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vectors.h"

typedef enum e_bool { TRUE, FALSE }	t_bool;

typedef enum e_obj_type
{
	sphere,
	plane,
	cylinder
}	t_obj_type;

typedef struct s_inter
{
	t_vec	p[4];
	double	t[4];
	t_vec	closest;
	t_bool	hit;
}			t_inter;

typedef struct s_obj
{
	t_obj_type	type;
	t_vec		dir;
	t_vec		pos;
	t_vec		color;
	double		radius;
	double		height;
	t_inter		hit;
}				t_obj;

#endif
