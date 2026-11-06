/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:57:03 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/17 09:07:27 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	*ft_opering(char *dest, const char *s1, unsigned int st, size_t n)
{
	size_t	i;

	i = 0;
	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = s1[st + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;
	char	*receive;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	ptr = (char *)s;
	if (start >= s_len)
	{
		ptr = (char *)malloc(1);
		if (ptr)
			ptr[0] = '\0';
		return (ptr);
	}
	if (len > s_len - start)
		len = s_len - start;
	receive = ft_opering(ptr, s, start, len);
	return (receive);
}
