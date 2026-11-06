/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:19:14 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/05 14:55:55 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest0;
	unsigned char	*src0;
	size_t			i;

	if (((!src || !dest) && (n > 0)) || (n >= SIZE_MAX / 2))
		return (NULL);
	dest0 = (unsigned char *)dest;
	src0 = (unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		while (n--)
		{
			dest0[n] = src0[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest0[i] = src0[i];
			i++;
		}
	}
	return (dest);
}
