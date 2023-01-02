/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:49:39 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/16 11:08:46 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str)
{
	long long int	nb;
	int				sign;
	int				i;
	int				decimals;

	nb = ft_atoi(str);
	i = 0;
	sign = 1;
	decimals = 1;
	if (str[i] == '-')
		sign = -1;
	i += (str[i] == '-');
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] == '.')
		++i;
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + str[i] - '0';
		++i;
		decimals *= 10;
	}
	nb *= sign;
	return ((float)nb / decimals);
}
