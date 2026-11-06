/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:51:23 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/05 14:53:08 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest0;
	unsigned char	*src0;

	i = 0;
	if ((!src || !dest) && n > 0)
		return (NULL);
	if (n >= SIZE_MAX / 2)
		return (NULL);
	dest0 = (unsigned char *)dest;
	src0 = (unsigned char *)src;
	while (i < n)
	{
		dest0[i] = src0[i];
		i++;
	}
	return (dest);
}
