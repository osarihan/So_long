/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:40:12 by osarihan          #+#    #+#             */
/*   Updated: 2022/03/03 12:08:32 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *src, int fd)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr(src, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		src = ft_strjoin(src, buffer);
	}
	free(buffer);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line[fd] = get_line(next_line[fd], fd);
	if (next_line[fd] == NULL)
		return (NULL);
	line = ft_read_line(next_line[fd]);
	next_line[fd] = ft_save(next_line[fd]);
	if (line[0] == '\0')
	{
		free(next_line[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}
