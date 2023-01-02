/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:09:57 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 15:44:11 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_line_error(int line_count)
{
	ft_putstr_fd("Error\nOn line ", STDERR_FILENO);
	ft_putnbr_fd(line_count, STDERR_FILENO);
}

int	ft_identifier_error(char *identifier, int line_count)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Unkwown identifier: ", STDERR_FILENO);
	ft_putendl_fd(identifier, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_missing_cam_error(void)
{
	ft_putendl_fd("Error\nMissing camera in scene", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_extra_cam_error(int line_count)
{
	ft_line_error(line_count);
	ft_putendl_fd(": Camera already declared earlier in scene", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_extra_light_error(int line_count, t_light_type type)
{
	ft_line_error(line_count);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (type == ambient)
		ft_putstr_fd("Ambient", STDERR_FILENO);
	else
		ft_putstr_fd("Positional", STDERR_FILENO);
	ft_putendl_fd(" light already declared earlier in scene", STDERR_FILENO);
	return (EXIT_FAILURE);
}
