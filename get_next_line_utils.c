/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:51:29 by mnazarya          #+#    #+#             */
/*   Updated: 2023/02/13 21:49:28 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c])
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	b;

	b = (char)c;
	if (!s)
		return (0);
	while (*s && *s != b)
		s++;
	if (*s == b)
		return ((char *)s);
	return (0);
}

char	*ft_find(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = -1;
	while (s[++i] && s[i] != '\n')
		str[i] = s[i];
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_remainder(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i));
	if (!str)
		return (0);
	j = 0;
	while (s[i] && s[++i])
		str[j++] = s[i];
	str[j] = '\0';
	free(s);
	return (str);
}
