/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:47:29 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/08 08:50:59 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	res = ft_strdup(s);
	if (!res || !f)
		return (res);
	i = 0;
	while (res[i])
	{
		res[i] = (*f)(i, res[i]);
		++i;
	}
	return (res);
}
