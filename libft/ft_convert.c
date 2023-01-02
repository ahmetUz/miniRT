/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:22:56 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:40:39 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_hex(unsigned int n, int maj)
{
	char	*res;

	if (maj)
		res = ft_itoa_base(n, "0123456789ABCDEF");
	else
		res = ft_itoa_base(n, "0123456789abcdef");
	return (res);
}

char	*ft_convert_ptr(uint64_t n)
{
	char	*res;
	char	*addr;

	addr = ft_itoa_base(n, "0123456789abcdef");
	if (!addr)
		return (addr);
	res = ft_strjoin("0x", addr);
	free(addr);
	return (res);
}
