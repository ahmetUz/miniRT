/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:56:57 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/19 10:05:40 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	size_t		i;
	const char	*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (!d && !s)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}
