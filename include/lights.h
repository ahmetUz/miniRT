/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:49:10 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/22 11:30:01 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

# include "vectors.h"

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
	double			brightness;
}					t_light;

unsigned int	ft_rgb_to_uint(t_vec rgb);

#endif
