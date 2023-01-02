/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:57:13 by plelez            #+#    #+#             */
/*   Updated: 2022/11/19 10:06:00 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	return (c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	long long int	res;
	int				sign;
	int				i;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit(nptr[i]))
	{
		res *= 10;
		res += nptr[i] - '0';
		++i;
	}
	res *= sign;
	return ((int)res);
}
