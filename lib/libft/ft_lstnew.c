/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:12:26 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/23 19:29:26 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dest;

	if (!content)
		return (NULL);
	dest = malloc(sizeof(t_list));
	if (!dest)
		return (NULL);
	dest->content = content;
	dest->next = NULL;
	return (dest);
}
