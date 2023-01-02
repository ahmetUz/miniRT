/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:50:22 by plelez            #+#    #+#             */
/*   Updated: 2022/11/19 10:05:34 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (d == s)
		return (d);
	if (d < s)
		return (ft_memcpy(d, s, n));
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		--n;
	}
	return (d);
}
