/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:39:19 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/26 13:14:07 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_maps *map)
{
	check_map_lenght(map);
	check_map_utils(map);
	check_map_rows(map);
	check_map_columns(map);
	return (1);
}

int	check_map_utils(t_maps *map)
{
	int		i;
	char	*str;
	int		hero;
	int		exit;
	int		coin;

	hero = 0;
	exit = 0;
	coin = 0;
	i = 0;
	while (i < map->count)
	{
		str = ft_strdup(map->map[i]);
		utils_check(map->map[i]);
		hero += utils_count(str, 'p');
		exit += utils_count(str, 'e');
		coin += utils_count(str, 'c');
		free(str);
		i++;
	}
	if (hero != 1 || exit != 1 || coin < 1)
		error(3);
	return (1);
}

void	utils_check(char *str)
{
	while (*str != '\0')
	{
		if(*str == 'P' || *str == 'C' || *str == '0' || *str == '1' || *str == 'E')
			str++;
		else
		{
			write(1, "Error\nHaritada istenmeyen karakter var\n", 40);
			exit(0);
		}
	}
}

int	utils_count(char *str, char c)
{
	int	hero;
	int	exit;
	int	coin;

	coin = 0;
	exit = 0;
	hero = 0;
	while (*str != '\0')
	{
		if (*str == 'P')
			hero++;
		else if (*str == 'E')
			exit++;
		else if (*str == 'C')
			coin++;
		str++;
	}
	if (c == 'e')
		return (exit);
	if (c == 'p')
		return (hero);
	if (c == 'c')
		return (coin);
	return (0);
}

int	check_map_lenght(t_maps *map)
{
	int				i;
	char			*str;
	char			*str2;
	unsigned int	a;

	i = 0;
	a = map->count;
	while (--a)
	{		
		str = ft_strdup(map->map[i]);
		if (map->map[i + 1] != NULL)
		{
			str2 = ft_strdup(map->map[i + 1]);
			if (ft_strlen(str) != ft_strlen(str2))
				error(4);
			free(str2);
		}
		free(str);
		i++;
	}
	return (1);
}
