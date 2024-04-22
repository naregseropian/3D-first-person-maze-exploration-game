/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:04:31 by szalazar          #+#    #+#             */
/*   Updated: 2024/02/28 13:59:23 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*read_text(int fd, char *static_buffer)
{
	char	*buffer;
	int		count;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	count = 1;
	while (!ft_gnl_strchr(static_buffer, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(static_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*ft_line(char *static_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] != '\n' && static_buffer[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i] != '\0')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i] != '\0')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char) * ft_strlen(static_buffer) - i + 1);
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i] != '\0')
		new_line[j++] = static_buffer[i++];
	new_line[j] = '\0';
	free(static_buffer);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_buffer = read_text(fd, static_buffer);
	if (!static_buffer)
	{
		free(static_buffer);
		return (NULL);
	}
	line = ft_line(static_buffer);
	static_buffer = ft_new_line(static_buffer);
	return (line);
}
