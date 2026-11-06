/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <maumonte@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:35:41 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/28 16:49:23 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **rest)
{
	char	*line;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!*rest || !**rest)
		return (NULL);
	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	if ((*rest)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (++j < i)
		line[j] = (*rest)[j];
	line[j] = '\0';
	temp = ft_strdup(*rest + i);
	free(*rest);
	*rest = temp;
	return (line);
}

void	clear_buffer_rest(char **buffer_rest, char *line, ssize_t byttes_read)
{
	if ((!line && *buffer_rest) || byttes_read == 0)
	{
		free(*buffer_rest);
		*buffer_rest = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer_rest;
	char		*buffer;
	char		*line;
	char		*temp;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer_rest, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(buffer_rest), buffer_rest = NULL, NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(buffer_rest, buffer);
		free(buffer_rest);
		buffer_rest = temp;
	}
	line = extract_line(&buffer_rest);
	clear_buffer_rest(&buffer_rest, line, bytes_read);
	return (free(buffer), line);
}
