/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes_errors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 08:57:07 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/23 08:59:07 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_reflect_error(int line_count, char *arg)
{
	ft_line_error(line_count);
	ft_putstr_fd(": Arg ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(" is not a valid reflection index", STDERR_FILENO);
	return (EXIT_FAILURE);
}
