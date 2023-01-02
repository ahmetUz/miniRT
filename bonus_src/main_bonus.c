/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:30:59 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 11:01:59 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		return (ft_param_error());
	if (ft_init_env(&env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (ft_init_mlx(&env) != EXIT_SUCCESS)
	{
		ft_mlx_clean(&env);
		return (EXIT_FAILURE);
	}
	if (ft_parse_scene(&env, argv[1]) != EXIT_SUCCESS)
	{
		ft_mlx_clean(&env);
		return (EXIT_FAILURE);
	}
	ft_raytracer(&env);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}
