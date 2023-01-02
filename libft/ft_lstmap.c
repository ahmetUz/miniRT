/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:57:13 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/09 10:32:22 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	res = ft_lstnew((*f)(lst->content));
	if (!res)
		return (NULL);
	if (!lst->next)
		return (res);
	res->next = ft_lstmap(lst->next, f, del);
	if (!res->next)
		ft_lstclear(&res, del);
	return (res);
}
