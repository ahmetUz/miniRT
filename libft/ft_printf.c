/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:18:14 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 17:54:07 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_get_next_char(const char *format)
{
	size_t	i;

	i = 1;
	while (ft_isflag(format[i]))
		++i;
	while (ft_isdigit(format[i]))
		++i;
	if (format[i] == '.')
	{
		++i;
		while (ft_isdigit(format[i]))
			++i;
	}
	if (ft_isspec(format[i]))
		++i;
	else
		return (1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;

	if (!format)
		return (0);
	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			++len;
			++i;
		}
		else
		{
			len += ft_printf_parsearg(&format[i + 1], ap);
			i += ft_get_next_char(&format[i]);
		}
	}
	return (len);
}
