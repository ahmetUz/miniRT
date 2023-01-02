/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:10:00 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:39:30 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision_pad(char *res, t_printfarg *args, size_t len)
{
	char	*tmp;

	if (len > args->precision)
	{
		tmp = res;
		res = ft_substr(res, 0, args->precision);
		if (!res)
			return (tmp);
		free(tmp);
	}
	return (res);
}

static char	*ft_fieldwidth_pad(char *res, t_printfarg *args, size_t len)
{
	char	*tmp;
	char	*padding;

	padding = ft_printf_create_buffer(args->width - len, ' ');
	if (!padding)
		return (res);
	tmp = res;
	if (args->flags & right_padding)
		res = ft_strjoin(tmp, padding);
	else
		res = ft_strjoin(padding, tmp);
	free(padding);
	if (!res)
		return (tmp);
	free(tmp);
	return (res);
}

char	*ft_printf_str_pad(char *res, t_printfarg *args)
{
	size_t	len;

	if (!res)
		return (res);
	len = ft_strlen(res);
	if (args->flags & nul_char)
		++len;
	if (args->flags & precision_flag)
	{
		res = ft_precision_pad(res, args, len);
		len = ft_strlen(res);
	}
	if (args->width && (int)args->width - (int)len > 0)
		res = ft_fieldwidth_pad(res, args, len);
	return (res);
}
