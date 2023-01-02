/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:53:19 by plelez            #+#    #+#             */
/*   Updated: 2022/11/19 10:06:16 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrim(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_istrim(s1[start], set))
		++start;
	end = ft_strlen(s1) - 1;
	while (ft_istrim(s1[end], set) && end >= 0)
		--end;
	if (end < 0)
		return ((char *)ft_calloc(1, 1));
	return (ft_substr(s1, start, end - start + 1));
}
