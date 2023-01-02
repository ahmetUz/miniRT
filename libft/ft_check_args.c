/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:06:19 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/12 15:35:24 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isargnum(char c)
{
	return (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'u');
}

int	ft_isspec(char c)
{
	if (ft_isargnum(c))
		return (1);
	return (c == '%' || c == 'c' || c == 'p' || c == 's');
}

int	ft_isflag(char c)
{
	if (c == ' ' || c == '-' || c == '0')
		return (1);
	return (c == '#' || c == '+');
}
