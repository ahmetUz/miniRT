/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:28:27 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 13:41:45 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	ft_args_len(char **args)
{
	int	i;

	i = 1;
	while (args[i])
		++i;
	return (i - 1);
}

int	ft_valid_double(char *arg)
{
	int	i;
	int	found_dot;

	found_dot = 0;
	i = 0;
	if (arg[i] == '-')
		++i;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			if (found_dot)
				return (0);
			found_dot = 1;
		}
		else if (!ft_isdigit(arg[i]))
			return (0);
		++i;
	}
	return (1);
}

int	ft_valid_uint(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		++i;
	}
	return (1);
}

int	ft_valid_fov(char *arg)
{
	double	value;

	value = ft_atod(arg);
	return (value >= 0 && value <= 180);
}

int	ft_valid_numarg(char *arg)
{
	double	value;

	value = ft_atod(arg);
	return (value > 0);
}
