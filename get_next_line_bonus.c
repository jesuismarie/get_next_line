/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:51:27 by mnazarya          #+#    #+#             */
/*   Updated: 2026/03/04 15:22:53 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_str(int fd, char *s)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(s);
			s = NULL;
			return (free(buf), NULL);
		}
		buf[n] = '\0';
		if (n == 0)
			break ;
		s = ft_strjoin(s, buf);
		if (!s)
			return (NULL);
		if (ft_strchr(s, '\n'))
			break ;
	}
	return (free(buf), s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[OPEN_MAX] = {NULL};

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	str[fd] = read_str(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_find(str[fd]);
	str[fd] = ft_remainder(str[fd]);
	if (line && !line[0])
		return (free(line), 0);
	return (line);
}
