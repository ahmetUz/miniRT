/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:49:10 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/26 15:41:58 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_BONUS_H
# define LIGHTS_BONUS_H

# include "vectors_bonus.h"

typedef enum e_light_type
{
	ambient,
	directional,
	positional
}	t_light_type;

typedef struct s_light
{
	t_light_type	type;
	t_vec			pos;
	t_vec			dir;
	t_vec			color;
	double			brightness;
}					t_light;

void			ft_uint_to_rgb(unsigned int color, t_vec *rgb);

unsigned int	ft_rgb_to_uint(t_vec *rgb);

#endif
