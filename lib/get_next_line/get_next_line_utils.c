/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <maumonte@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:41:16 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/23 13:23:53 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		tamanho;
	int		i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	tamanho = i + 1;
	ptr = (char *)malloc(tamanho * sizeof(char));
	if (!ptr)
		return (ptr);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	count0;
	size_t	count1;
	size_t	i;
	char	*ptr;

	count0 = ft_strlen(s1);
	count1 = ft_strlen(s2);
	ptr = (char *)malloc((count0 + count1 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count0)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < count1)
	{
		ptr[count0 + i] = s2[i];
		i++;
	}
	ptr[count0 + i] = '\0';
	return (ptr);
}

int	ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}
