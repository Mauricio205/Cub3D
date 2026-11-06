/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:35:24 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/23 23:44:57 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*str;

	if (!lst)
		return (0);
	str = lst;
	i = 0;
	while (str != NULL)
	{
		i++;
		str = str->next;
	}
	return (i);
}
