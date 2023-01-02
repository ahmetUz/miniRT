/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsearg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:40:40 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:05:53 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flagenum	ft_printf_parseflag(char c)
{
	if (c == ' ')
		return (space_padding);
	if (c == '0')
		return (zero_padding);
	if (c == '-')
		return (right_padding);
	if (c == '#')
		return (alt_form);
	if (c == '+')
		return (plus_sign);
	return (no_flags);
}

static size_t	ft_printf_parse_numarg(const char *format)
{
	char	*tmp;
	size_t	end;
	size_t	len;

	end = 0;
	while (ft_isdigit(format[end]))
		++end;
	tmp = ft_substr(format, 0, end);
	if (!tmp)
		return (0);
	len = ft_atoi(tmp);
	free(tmp);
	return (len);
}

static void	ft_printf_parse_args(const char *format, t_printfarg *args)
{
	size_t	i;

	i = 0;
	while (ft_isflag(format[i]))
	{
		args->flags |= ft_printf_parseflag(format[i]);
		++i;
	}
	if (ft_isdigit(format[i]))
	{
		args->width = ft_printf_parse_numarg(&format[i]);
		while (ft_isdigit(format[i]))
			++i;
	}
	if (format[i] == '.')
	{
		args->flags |= precision_flag;
		++i;
		args->precision = ft_printf_parse_numarg(&format[i]);
		while (ft_isdigit(format[i]))
			++i;
	}
}

size_t	ft_printf_parsearg(const char *format, va_list ap)
{
	size_t			i;
	size_t			len;
	t_printfarg		args;

	i = 0;
	len = 0;
	args.flags = 0;
	args.width = 0;
	args.precision = 0;
	ft_printf_parse_args(format, &args);
	while (format[i] && !ft_isspec(format[i]))
		++i;
	if (!format[i])
	{
		write(1, "%", 1);
		return (1);
	}
	len += ft_printf_printarg(format[i], ap, &args);
	return (len);
}
