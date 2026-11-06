/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 01:03:26 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/26 02:32:31 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	if (i == n)
		return (NULL);
	if (!s || n >= SIZE_MAX / 2)
		return (NULL);
	dest = (unsigned char *)s;
	while (i < n)
	{
		if (*dest == (unsigned char)c)
			return ((unsigned char *)dest);
		dest++;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((unsigned char *)dest);
	return (NULL);
}
