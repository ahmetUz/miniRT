/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:49:39 by ple-lez           #+#    #+#             */
/*   Updated: 2022/12/18 09:17:29 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	long long int	nb;
	int				sign;
	int				i;
	int				decimals;

	nb = ft_atoi(str);
	i = 0;
	sign = 1;
	decimals = 1;
	if (str[0] == '-')
		sign = -1;
	i += (str[0] == '-');
	nb *= sign;
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
	return ((double)nb / decimals);
}
