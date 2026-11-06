/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:03:16 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/05 14:56:34 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*array;
	size_t			i;

	if (!s || n >= SIZE_MAX / 2)
		return ;
	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
	return ;
}
