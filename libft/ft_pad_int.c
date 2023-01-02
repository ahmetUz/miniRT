/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:09:16 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 18:56:20 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_left_pad(char *res, char *padding, t_pflags flags)
{
	char	*tmp;

	if ((res[0] == '-' || res[0] == '+') && (flags & zero_padding))
	{
		tmp = ft_substr(res, 0, 1);
		padding = ft_strjoin(tmp, padding);
		res = ft_strjoin(padding, &res[1]);
		free(padding);
		free(tmp);
		return (res);
	}
	if (flags & alt_form)
	{
		tmp = ft_substr(res, 0, 2);
		padding = ft_strjoin(tmp, padding);
		res = ft_strjoin(padding, &res[2]);
		free(padding);
		free(tmp);
		return (res);
	}
	return (ft_strjoin(padding, res));
}

static char	*ft_precision_pad(char *res, t_printfarg *args)
{
	char	*tmp;
	char	*padding;
	size_t	len;

	len = ft_strlen(res);
	if (res[0] == '-' || res[0] == '+')
		++args->precision;
	if (args->flags & alt_form)
		args->precision += 2;
	if ((int)args->precision - (int)len > 0)
	{
		args->flags |= zero_padding;
		padding = ft_printf_bufferpad(args->precision - len, zero_padding);
		tmp = res;
		res = ft_left_pad(res, padding, args->flags);
		free(tmp);
		free(padding);
	}
	args->flags &= ~zero_padding;
	args->flags &= ~alt_form;
	args->flags |= space_padding;
	return (res);
}

static char	*ft_fieldwidth_pad(char *res, t_printfarg *args, size_t len)
{
	char	*tmp;
	char	*padding;

	padding = ft_printf_bufferpad(args->width - len, args->flags);
	tmp = res;
	if (args->flags & right_padding)
		res = ft_strjoin(tmp, padding);
	else
		res = ft_left_pad(res, padding, args->flags);
	free(tmp);
	free(padding);
	return (res);
}

char	*ft_printf_int_pad(char *res, t_printfarg *args)
{
	char	*tmp;
	size_t	len;

	if (args->flags & plus_sign && res[0] != '-')
	{
		tmp = res;
		res = ft_strjoin("+", res);
		free(tmp);
	}
	if (args->flags & precision_flag)
		res = ft_precision_pad(res, args);
	if (!res)
		return (NULL);
	len = ft_strlen(res);
	if (args->width && (int)args->width - (int)len > 0)
		res = ft_fieldwidth_pad(res, args, len);
	else if (!(args->flags & precision_flag)
		&& (args->flags & space_padding) && res[0] != '-')
	{
		tmp = res;
		res = ft_strjoin(" ", tmp);
		free(tmp);
	}
	return (res);
}
