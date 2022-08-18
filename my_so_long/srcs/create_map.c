/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:05:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/18 16:27:37 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	close (df);
	return (count);
}

int	rows_count(char **argv)
{
	int		i;
	int		j;
	int		df;
	char	*str;

	str = malloc(1000);
	df = open(argv[1], O_RDONLY);
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

void	rc(t_maps *reads, char **argv)
{
	reads->count = line_count(argv);
	reads->row_count = rows_count(argv);
}

void	create_map(char **argv, t_maps *reads)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	rc(reads, argv);
	reads->map = malloc(sizeof(char **) * reads->count + 1);
	reads->fd = open(argv[1], O_RDONLY);
	while (i < reads->count)
	{
		j = 0;
		str = calloc(sizeof(char *), sizeof(str));
		str = get_next_line(reads->fd);
		reads->map[i] = calloc(sizeof(char *), reads->row_count);
		while (str[j] != '\0')
		{
			if ((str[j] == '1' || str[j] == '0') || str[j] == 'C' || \
					str[j] == 'P' || str[j] == 'E')
				reads->map[i][j] = str[j];
			j++;
		}
		free(str);
		i++;
	}
	close(reads->fd);
}
