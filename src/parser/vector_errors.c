/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:38:29 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 15:44:36 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_coord_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid coordinate", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_dir_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid direction vector", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_color_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid RGB color", STDERR_FILENO);
	return (EXIT_FAILURE);
}
