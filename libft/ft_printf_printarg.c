/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printarg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:24:29 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:40:18 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_nulchar(char *res, t_pflags flags, size_t len)
{
	if (flags & right_padding)
	{
		write(1, "\0", 1);
		write(1, res, ft_strlen(res));
		return ;
	}
	write(1, res, len);
	write(1, "\0", 1);
	return ;
}

size_t	ft_printf_printarg(char c, va_list ap, t_printfarg *args)
{
	char	*res;
	size_t	len;

	res = ft_printf_parsespec(c, ap, args);
	if (!res)
		return (0);
	len = ft_strlen(res);
	if (args->flags & nul_char)
	{
		ft_printf_nulchar(res, args->flags, len);
		++len;
	}
	else
		write(1, res, len);
	free(res);
	return (len);
}
