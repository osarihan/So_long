/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:05:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/24 17:27:11 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*

int	line_count(char *mappath)
{
	int		count;
	char	*line;
	int		df;

	count = 1;
	df = open(mappath, O_RDONLY);
	if (df < 0)
		error ();
	line = malloc(100);
	while (read(df, line, 1))
	{
		if (ft_strchr(line, '\n'))
		{
			count++;
		}
	}
	close (df);
	free(line);
	return (count);
}


int	line_count(char **argv)
{
	int		count;
	char	*line;
	int		df;

	count = 0;
	df = open (argv[1], O_RDONLY);
	if (df < 0)
		error ();
	line = get_next_line (df);
	while (line != NULL)
	{
		count++;
		line = get_next_line (df);
	}
	free(line);
	close (df);
	return (count);
}

int	rows_count(char **argv)
{
	int		i;
	int		j;
	int		df;
	char	*str2;
	int		len;

	len = 0;
	len = ft_strlen(argv[0]);
	str2 = malloc(sizeof(char *) * len);
	df = open(argv[1], O_RDONLY);
	i = read(df, str2, 100);
	i = 0;
	j = 0;
	while (str2[j] != '\n')
	{
		j++;
	}
	str2[j] = '\0';
	j = 0;
	while (str2[j] != '\0')
	{
		j++;
	}
	close (df);
	free (str2);
	printf("ds::::%d\n", j);
	return (j);
}

void	rc(t_maps *reads, char **argv)
{
	reads->count = line_count(argv);
	reads->row_count = rows_count(argv);
	printf("rowc:%d\n", reads->row_count);
	printf("cont:%d\n", reads->count);
}

void	create_map(char **argv, t_maps *reads)
{
	int		i;
	int		j;
	printf("milestone1\n");
	i = 0;
	rc(reads, argv);
	reads->map = malloc(sizeof(char **) * (reads->count) + 1);
	reads->fd = open(argv[1], O_RDONLY);
	while (i < reads->count)
	{
		printf("milestone2\n");
		j = 0;
		printf("milestone3\n");
		printf("milestone4\n");
		reads->map[i] = calloc(sizeof(char *), reads->row_count + 1);
		printf("milestone5\n");
		while (reads->map[i] != NULL)
		{
			printf("milestone7\n");
			reads->map[i] = get_next_line(reads->fd);	
			printf("milestone10\n");
		}
		printf("milestone9\n");
		i++;
	}
	printf("milestone8\n");
	close(reads->fd);
}


void	create_map(char **argv, t_maps *map)
{
	int	i;
	int	j;

	i = 0;
	rc(map, argv);
	map->map = ft_calloc(map->count + 1, sizeof(char *));
	map->fd = open(argv[1], O_RDONLY);
	printf("ds::::%d\n", map->fd);
	while (i < map->count)
	{
		j = 0;
		map->map[i] = malloc(sizeof(char *) * map->row_count + 1);
		map->map[i] = get_next_line(map->fd);
		map->map[i][map->row_count] = '\0';
		i++;
	}
	close(map->fd);
}
*/

#include "so_long.h"

int	count(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		write(1, "hata\n", 5);
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
