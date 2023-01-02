/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:24:48 by plelez            #+#    #+#             */
/*   Updated: 2022/11/19 10:05:21 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(const char *s)
{
	if (!s)
		return (0);
	return (ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_getlen(s1);
	s2_len = ft_getlen(s2);
	res = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!res)
		return (res);
	res = (char *)ft_memmove(res, s1, s1_len);
	ft_memmove(res + s1_len, s2, s2_len);
	return (res);
}
