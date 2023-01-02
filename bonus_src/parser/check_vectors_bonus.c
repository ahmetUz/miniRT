/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vectors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:48:48 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/21 13:41:48 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	ft_count_commas(char *arg)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (arg[i])
	{
		if (arg[i] == ',')
			++nb;
		++i;
	}
	return (nb);
}

int	ft_valid_coord(char *arg)
{
	int		i;
	char	**args;

	if (ft_count_commas(arg) != 2)
		return (0);
	args = ft_split(arg, ',');
	i = 0;
	while (i < 3)
	{
		if (!ft_valid_double(args[i]))
		{
			ft_clear_tab(args);
			return (0);
		}
		++i;
	}
	ft_clear_tab(args);
	return (1);
}

int	ft_valid_dir(char *arg)
{
	int		i;
	double	value;
	char	**args;

	if (ft_count_commas(arg) != 2)
		return (0);
	args = ft_split(arg, ',');
	i = 0;
	while (i < 3)
	{
		if (!ft_valid_double(args[i]))
		{
			ft_clear_tab(args);
			return (0);
		}
		value = ft_atod(args[i]);
		if (value < -1 || value > 1)
		{
			ft_clear_tab(args);
			return (0);
		}
		++i;
	}
	ft_clear_tab(args);
	return (1);
}

int	ft_valid_color(char *arg)
{
	int		i;
	int		value;
	char	**args;

	if (ft_count_commas(arg) != 2)
		return (0);
	args = ft_split(arg, ',');
	i = 0;
	while (i < 3)
	{
		if (!ft_valid_uint(args[i]))
		{
			ft_clear_tab(args);
			return (0);
		}
		value = ft_atoi(args[i]);
		if (value < 0 || value > 255)
		{
			ft_clear_tab(args);
			return (0);
		}
		++i;
	}
	ft_clear_tab(args);
	return (1);
}
