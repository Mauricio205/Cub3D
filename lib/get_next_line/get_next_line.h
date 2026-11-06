/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <maumonte@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:43:18 by maumonte          #+#    #+#             */
/*   Updated: 2025/07/28 12:14:39 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*extract_line(char **rest);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
