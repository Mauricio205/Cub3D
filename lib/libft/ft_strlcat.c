/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 02:14:38 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/26 04:09:05 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count0;
	size_t	count1;
	size_t	i;

	if (!src || !dst)
		return (0);
	count0 = 0;
	count1 = 0;
	while (dst[count1] && count1 < size)
		count1++;
	while (src[count0])
		count0++;
	if (count1 == size)
		return (count0 + size);
	i = 0;
	while (src[i] && (count1 + i) < size - 1)
	{
		dst[count1 + i] = src[i];
		i++;
	}
	dst[count1 + i] = '\0';
	return (count0 + count1);
}
