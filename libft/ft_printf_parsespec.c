/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsespec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:41:30 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:11:22 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_parsestr(va_list ap, t_printfarg *args)
{
	char	*res;

	res = va_arg(ap, char *);
	if (!res)
		res = "(null)";
	res = ft_strdup(res);
	return (ft_printf_str_pad(res, args));
}

static char	*ft_parseptr(va_list ap, t_printfarg *args)
{
	char		*res;
	uint64_t	addr;

	addr = va_arg(ap, uint64_t);
	if (addr != 0)
		res = ft_convert_ptr(addr);
	else
		res = ft_strdup("(nil)");
	return (ft_printf_int_pad(res, args));
}

static char	*ft_parsechar(char c, t_printfarg *args)
{
	char	*arg;
	char	*res;

	arg = (char *)ft_calloc(sizeof(char), 2);
	if (!arg)
		return (arg);
	arg[0] = c;
	if (!c)
		args->flags |= nul_char;
	res = ft_printf_str_pad(arg, args);
	return (res);
}

char	*ft_printf_parsespec(char c, va_list ap, t_printfarg *args)
{
	char	tmp;

	if (ft_isargnum(c))
		return (ft_printf_parsenum(c, ap, args));
	if (c == '%')
		return (ft_parsechar('%', args));
	if (c == 'c')
	{
		tmp = (char)va_arg(ap, int);
		return (ft_parsechar(tmp, args));
	}
	if (c == 'p')
		return (ft_parseptr(ap, args));
	return (ft_parsestr(ap, args));
}
