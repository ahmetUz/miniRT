/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:15:25 by plelez            #+#    #+#             */
/*   Updated: 2022/11/08 11:15:56 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_caplen(int n)
{
	if (n < 0)
		return (0);
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	s_len;
	size_t	r_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((int)(s_len - start) <= (int)len)
		r_len = ft_caplen(s_len - start);
	else
		r_len = len;
	res = (char *)malloc(sizeof(char) * (r_len + 1));
	if (!res)
		return (res);
	i = 0;
	while (i < r_len && i + start < s_len)
	{
		res[i] = s[i + start];
		++i;
	}
	res[i] = '\0';
	return (res);
}
