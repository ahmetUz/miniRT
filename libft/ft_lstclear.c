/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:45:09 by ple-lez           #+#    #+#             */
/*   Updated: 2022/11/08 11:30:16 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	if ((*lst)->content && del)
		(*del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
