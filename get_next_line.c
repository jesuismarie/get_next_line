/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:51:27 by mnazarya          #+#    #+#             */
/*   Updated: 2023/08/02 18:38:04 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *s)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
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
	static char	*str = NULL;

	line = NULL;
	if ((fd != 0 && fd < 2) || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_find(str);
	str = ft_remainder(str);
	if (line && !line[0])
		return (free(line), NULL);
	return (line);
}
