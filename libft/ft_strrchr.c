/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:06:52 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/08 10:58:06 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pos;

	i = 0;
	pos = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = (char *)&s[i];
		++i;
	}
	if (s[i] == (char)c)
		pos = (char *)&s[i];
	return (pos);
}
