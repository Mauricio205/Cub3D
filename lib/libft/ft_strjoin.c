/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:57:54 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/26 03:34:43 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count0;
	size_t	count1;
	size_t	i;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	count0 = ft_strlen(s1);
	count1 = ft_strlen(s2);
	ptr = (char *)malloc((count0 + count1 + 1) * sizeof(char));
	i = 0;
	while (ptr && i < count0)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (ptr && i < count1)
	{
		ptr[count0 + i] = s2[i];
		i++;
	}
	ptr[count0 + i] = '\0';
	return (ptr);
}
