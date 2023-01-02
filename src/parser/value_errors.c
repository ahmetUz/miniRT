/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:50:52 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/20 15:42:19 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_double_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid double number", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_fov_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid FOV", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_numarg_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid parameter", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_argcount_error(int line_count, int arg_count, int expected)
{
	ft_line_error(line_count);
	if (arg_count > expected)
		ft_putendl_fd(": Too many arguments", STDERR_FILENO);
	else
		ft_putendl_fd(": Missing arguments", STDERR_FILENO);
	ft_putstr_fd("Expected ", STDERR_FILENO);
	ft_putnbr_fd(expected, STDERR_FILENO);
	ft_putstr_fd(", got ", STDERR_FILENO);
	ft_putnbr_fd(arg_count, STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
	return (EXIT_FAILURE);
}
