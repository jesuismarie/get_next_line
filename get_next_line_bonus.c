/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:51:36 by mnazarya          #+#    #+#             */
/*   Updated: 2023/08/02 18:38:01 by mnazarya         ###   ########.fr       */
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
			free(buf);
			return (0);
		}
		buf[n] = '\0';
		if (n == 0)
			break ;
		s = ft_strjoin(s, buf);
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[OPEN_MAX];

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	str[fd] = read_str(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = ft_find(str[fd]);
	str[fd] = ft_remainder(str[fd]);
	if (line && !line[0])
	{
		free(line);
		return (0);
	}
	return (line);
}
