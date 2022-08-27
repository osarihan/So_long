/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:05:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 14:18:51 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nMap Okunamadı\n", 22);
		exit(1);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

int	rows_count(char *argv)
{
	int		i;
	int		j;
	int		df;
	char	*str;

	str = malloc(1000);
	df = open(argv, O_RDONLY);
	i = read(df, str, 100);
	i = 0;
	j = 0;
	while (str[j] != '\n')
	{
		j++;
	}
	str[j] = '\0';
	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	close (df);
	free (str);
	return (j);
}

void	create_map(char *path, t_maps *map)
{
	int	i;
	int	j;
	int	asd;
	int	efg;

	map->count = count(path);
	map->row_count = rows_count(path);
	asd = map->count;
	efg = map->row_count;
	i = 0;
	map->map = ft_calloc(map->count, sizeof(char *));
	map->fd = open(path, O_RDONLY);
	while (i < asd)
	{
		j = 0;
		map->map[i] = get_next_line(map->fd);
		if (map->map[i])
			map->map[i][efg] = '\0';
		i++;
	}
	close (map->fd);
}
