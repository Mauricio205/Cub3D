/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 02:56:24 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/26 02:45:52 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*d1;
	const unsigned char	*d2;

	if ((!s1 && !s2) || n >= SIZE_MAX / 2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	d1 = (const unsigned char *)s1;
	d2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	return (0);
}
