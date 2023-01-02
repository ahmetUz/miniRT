/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:51:02 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 16:34:21 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

# include <mlx.h>

# define PNONE "none"
# define RING "ring"
# define STRIPE "stripes"
# define CHECKER "checker"

typedef enum e_obj_perturbation_type
{
	none,
	ring,
	stripe,
	checker
}	t_perturb_type;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		lsize;
	int		endian;
}			t_img;

typedef struct s_texture
{
	t_img	img;
	char	*path;
	int		width;
	int		height;
}	t_texture;

unsigned int	ft_read_img(t_img *img, int x, int y);
unsigned int	ft_get_texture_color(t_texture *texture, double u, double v);

#endif
