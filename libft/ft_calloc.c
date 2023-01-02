/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:01:05 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/25 15:25:22 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	res = (unsigned char *)malloc(nmemb * size);
	if (!res)
		return (res);
	ft_bzero(res, nmemb * size);
	return ((void *)res);
}
