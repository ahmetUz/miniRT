/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:02:29 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/08 10:55:25 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pos;
	int		i;

	i = 0;
	pos = NULL;
	while (s[i] && s[i] != (char)c)
		++i;
	if (s[i] == (char)c)
		pos = (char *)&s[i];
	return (pos);
}
