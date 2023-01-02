/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:35:02 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 16:33:43 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include "libft.h"
# include "lights_bonus.h"
# include "objects_bonus.h"
# include "raytracing_bonus.h"
# include "textures_bonus.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# define AMBIENT "A"
# define CAMERA "C"
# define POSLIGHT "L"
# define SPHERE "sp"
# define CYLINDER "cy"
# define CONE "co"
# define PLANE "pl"
# define TRIANGLE "tr"


typedef struct s_env
{
	int			nb_obj;
	int			nb_light;
	void		*mlx;
	void		*window;
	t_img		*img;
	t_cam		*cam;
	t_list		*objs;
	t_list		*lights;
	t_list		*imgs;
}				t_env;

int				ft_param_error(void);
int				ft_missing_cam_error(void);
int				ft_open_error(char *filename);
int				ft_read_error(char *filename);
int				ft_filename_error(char *filename);
int				ft_extra_cam_error(int line_count);

void			ft_line_error(int line_count);

int				ft_xpm_error(char *arg);
int				ft_fov_error(int line_count, char *arg);
int				ft_dir_error(int line_count, char *arg);
int				ft_coord_error(int line_count, char *arg);
int				ft_color_error(int line_count, char *arg);
int				ft_double_error(int line_count, char *arg);
int				ft_numarg_error(int line_count, char *arg);
int				ft_reflect_error(int line_count, char *arg);
int				ft_texture_error(int line_count, char *arg);
int				ft_perturbation_error(int line_count, char *arg);

int				ft_extra_light_error(int line_count, t_light_type type);
int				ft_identifier_error(char *identifier, int line_count);
int				ft_argcount_error(int line_count, int arg_count, int expected);

int				ft_args_len(char **args);
int				ft_check_light_exists(t_env *env, t_light_type type);

int				ft_valid_dir(char *arg);
int				ft_valid_fov(char *arg);
int				ft_valid_uint(char *arg);
int				ft_valid_coord(char *arg);
int				ft_valid_color(char *arg);
int				ft_valid_double(char *arg);
int				ft_valid_numarg(char *arg);
int				ft_valid_reflect(char *arg);
int				ft_valid_texture(char *arg);
int				ft_valid_perturbation(char *arg);

void			ft_parse_coord(char *arg, t_vec *vec);
void			ft_parse_color(char *arg, t_vec *vec);

int				ft_parse_scene(t_env *env, char *filename);
int				ft_parse_line(t_env *env, char *line, int line_count);
int				ft_parse_cone(t_env *env, char **args, int line_count);
int				ft_parse_light(t_env *env, char **args, int line_count);
int				ft_parse_plane(t_env *env, char **args, int line_count);
int				ft_parse_camera(t_env *env, char **args, int line_count);
int				ft_parse_sphere(t_env *env, char **args, int line_count);
int				ft_parse_cylinder(t_env *env, char **args, int line_count);
int				ft_parse_texture(t_env *env, t_texture *texture, char *arg);
int				ft_parse_triangle(t_env *env, char **args, int line_count);

t_perturb_type	ft_parse_perturbation(char *arg);

#endif
