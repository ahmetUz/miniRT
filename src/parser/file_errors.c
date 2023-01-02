/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:57:47 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 15:58:05 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_param_error(void)
{
	ft_putendl_fd("Error\nUsage: ./miniRT path_to_scene.rt", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_filename_error(char *filename)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putendl_fd(" is an invalid scene name", STDERR_FILENO);
	ft_putendl_fd("Valid scene name ends in .rt", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_open_error(char *filename)
{
	ft_putstr_fd("Error\nCannot open ", STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_read_error(char *filename)
{
	ft_putstr_fd("Error\nCannot read ", STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
	return (EXIT_FAILURE);
}
