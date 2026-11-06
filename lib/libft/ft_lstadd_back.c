/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 06:26:21 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/24 06:56:43 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dest;

	if (!lst || !new)
		return ;
	while (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	dest = *lst;
	while (dest->next)
		dest = dest->next;
	dest->next = new;
}
