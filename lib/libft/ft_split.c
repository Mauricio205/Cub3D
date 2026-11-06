/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:20:41 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/01 10:28:29 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strdup_range(char const *start, char const *end)
{
	size_t	i;
	size_t	len;
	char	*dest;

	len = end - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = start[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_fill_split(char const *s, char c, char **dest, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] && j < count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		dest[j] = ft_strdup_range(s + start, s + i);
		if (!dest[j])
		{
			while (j--)
				free(dest[j]);
			free(dest);
			return (NULL);
		}
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	dest = (char **)malloc((count + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (!ft_fill_split(s, c, dest, count))
		return (NULL);
	return (dest);
}
