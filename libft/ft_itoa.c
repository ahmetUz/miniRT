/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:31:55 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/08 07:46:52 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nblen(int n)
{
	int	res;

	res = 1;
	if (n < 0)
		++res;
	while (n / 10)
	{
		n /= 10;
		++res;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t			i;
	long long int	nb;
	char			*res;

	i = ft_nblen(n);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (res);
	nb = n;
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	else if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		--i;
		res[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
