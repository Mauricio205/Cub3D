/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:42:21 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/24 11:57:10 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dest;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		dest = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = dest;
	}
	*lst = NULL;
}
