/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 10:52:36 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 12:45:46 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (-1);
		i++;
	}
	return (i);
}

static int	is_valid(char *str)
{
	int		i;
	char	*max;

	if (!str || !*str)
		return (0);
	i = 0;
	while (*str == ' ')
		str++;
	if (!*str)
		return (0);
	while (*str == '0')
		str++;
	if (count_digits(str) > 3)
		return (0);
	if (count_digits(str) == -1)
		return (0);
	if (i == 3)
	{
		max = "255";
		if (ft_strncmp(str, max, 3) > 0)
			return (0);
	}
	return (1);
}

int	is_valid_color(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	while (mat[i])
	{
		if (!is_valid(mat[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_texture(char *line)
{
	int		i;
	int		j;
	char	**mat;

	i = 0;
	while (line[i] == ' ')
		i++;
	mat = ft_split(line + i, ' ');
	j = 0;
	while (mat[j])
		j++;
	if (j != 1)
	{
		ft_free_map(mat);
		return (0);
	}
	ft_free_map(mat);
	return (1);
}

char	*remove_reverse_space(char *line)
{
	int		len;
	char	*s;

	len = ft_strlen(line) - 1;
	while (len >= 0 && (line[len] == ' ' || line[len] == '\n'))
		len--;
	s = malloc(len + 2);
	if (!s)
		return (NULL);
	ft_memmove(s, line, len + 1);
	s[len + 1] = '\0';
	return (s);
}
