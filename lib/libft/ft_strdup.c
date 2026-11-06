/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:42:13 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/01 07:28:05 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
	if (ptr == NULL)
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
