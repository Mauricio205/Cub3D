/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:49:20 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/05 14:55:11 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	if (!s || n >= SIZE_MAX / 2)
		return (NULL);
	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
