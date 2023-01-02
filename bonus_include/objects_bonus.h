/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:56:47 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 10:53:23 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H

# include "textures_bonus.h"
# include "vectors_bonus.h"

typedef enum e_bool { TRUE, FALSE }	t_bool;

typedef enum e_obj_type
{
	sphere,
	plane,
	cylinder,
	cone,
	triangle
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
	t_obj_type		type;
	t_vec			dir;
	t_vec			pos;
	t_vec			color;
	t_vec			x_axis;
	t_vec			y_axis;
	t_vec			som1;
	t_vec			som2;
	t_vec			som3;
	t_inter			hit;
	double			radius;
	double			height;
	double			reflection;
	t_perturb_type	perturbation;
	t_texture		texture;
}					t_obj;

#endif
