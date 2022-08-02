/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:05:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/01 17:55:04 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int line_count(char **argv)
{
	int count;
	int fd;
	char *line;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error();
	line = get_next_line(fd);
	while(line != NULL)
	{
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return(count);
}

char **create_map(char **argv, maps *read)
{
	int i;
	int j;
	int count;
	int	sıracount;
	
	count = line_count(argv);
	read->map = malloc(sizeof(char) * count + 1);
	while(argv[1][i] != '\0')
	{
	
	}
}

int *map_check(int *map, char **argv, utils *datas)
{	
	datas = utils_count(argv, datas);
	if (datas->coin <= 0)
		error();
	else if(datas->exit != 1)
		error();
	else if(datas->hero != 1)
		error();
}

utils *utils_count(char **argv, utils *count)
{
	int	i;
	i = 0;
	while(argv[1][i] != '\0')
	{
		if (argv[1][i++] == '1')
			count->wall += 1;
		else if(argv[1][i++] == '0')
			count->empty_wall += 1;
		else if(argv[1][i++] == 'C')
			count->coin += 1;
		else if(argv[1][i++] == 'E')
			count->exit += 1;
		else if(argv[1][i++] == 'P')
			count->hero += 1;
		else
			error();
	}
}