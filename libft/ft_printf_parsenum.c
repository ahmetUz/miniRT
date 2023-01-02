/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsenum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:55:49 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:45:15 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_parseint(va_list ap, t_printfarg *args)
{
	args->flags &= ~alt_form;
	return (ft_itoa(va_arg(ap, int)));
}

static char	*ft_printf_parseuint(va_list ap, t_printfarg *args)
{
	args->flags &= ~plus_sign;
	args->flags &= ~alt_form;
	return (ft_itoa_base((unsigned int)va_arg(ap, int), "0123456789"));
}

static char	*ft_printf_parsehex(va_list ap, t_printfarg *args, int maj)
{
	char	*res;
	char	*tmp;

	args->flags &= ~plus_sign;
	res = ft_convert_hex((unsigned int)va_arg(ap, int), maj);
	if (!res)
		return (NULL);
	if (args->flags & alt_form && res[0] != '0')
	{
		tmp = res;
		if (maj)
			res = ft_strjoin("0X", res);
		else
			res = ft_strjoin("0x", res);
		free(tmp);
	}
	return (res);
}

char	*ft_printf_parsenum(char c, va_list ap, t_printfarg *args)
{
	char	*res;

	if (c == 'd' || c == 'i')
		res = ft_printf_parseint(ap, args);
	else if (c == 'u')
		res = ft_printf_parseuint(ap, args);
	else
		res = ft_printf_parsehex(ap, args, c == 'X');
	if (res)
		res = ft_printf_int_pad(res, args);
	return (res);
}
