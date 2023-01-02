/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:47:07 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/08 09:58:31 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = 0;
	dst_len = ft_strlen(dst);
	if (size < dst_len)
		src_len += size;
	else
		src_len += dst_len;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (src_len);
}
