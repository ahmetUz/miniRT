/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:25:44 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/11 20:31:40 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_reslen(uint64_t n, int div)
{
	int	res;

	res = 0;
	while (n / div)
	{
		++res;
		n /= div;
	}
	return (res);
}

char	*ft_itoa_base(uint64_t nb, char *base)
{
	char		*res;
	int			div;
	int			len;

	div = ft_strlen(base);
	len = ft_reslen(nb, div);
	res = (char *)ft_calloc(sizeof(char), len + 2);
	if (!res)
		return (res);
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[len] = base[nb % div];
		nb /= div;
		--len;
	}
	return (res);
}
