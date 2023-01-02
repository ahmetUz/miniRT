/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_errors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:57:45 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/28 14:48:57 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_perturbation_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid perturbation", STDERR_FILENO);
	ft_putstr_fd("List of valid args: ", STDERR_FILENO);
	ft_putendl_fd("none, ring, stripes, checker", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_texture_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid texture", STDERR_FILENO);
	ft_putstr_fd("Valid textures must be a xpm file ", STDERR_FILENO);
	ft_putendl_fd("with read permissions", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_xpm_error(char *arg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid xpm file", STDERR_FILENO);
	return (EXIT_FAILURE);
}
