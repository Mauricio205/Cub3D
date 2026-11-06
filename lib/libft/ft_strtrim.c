/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:24:14 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/21 09:17:38 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	count = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = count;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	dest = (char *)malloc((j - i + 1) * sizeof(char));
	count = 0;
	while (i < j)
	{
		dest[count] = s1[i];
		count++;
		i++;
	}
	dest[count] = '\0';
	return (dest);
}
