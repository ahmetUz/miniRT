/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:01:34 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:13:20 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_create_buffer(size_t len, char c)
{
	char	*res;

	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (res);
	res = (char *)ft_memset(res, c, len);
	return (res);
}

char	*ft_printf_bufferpad(size_t len, t_pflags flags)
{
	char	c;

	if (flags & right_padding)
		c = ' ';
	else if (flags & zero_padding)
		c = '0';
	else
		c = ' ';
	return (ft_printf_create_buffer(len, c));
}
