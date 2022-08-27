/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:12:02 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 14:18:41 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_rows(t_maps *map)
{
	char	*str;
	int		j;

	j = 0;
	str = ft_strdup(map->map[0]);
	while (str[j] != '\n' && str[j + 1] != '\0')
	{
		if (str[j] != '1')
			error(2);
		j++;
	}
	free(str);
	str = ft_strdup(map->map[map->count - 1]);
	j = 0;
	while (str[j] != '\n' && str[j + 1] != '\0')
	{
		if (str[j] != '1')
			error(2);
		j++;
	}
	free(str);
	return (1);
}

int	check_map_columns(t_maps *map)
{
	int		i;
	int		j;
	char	str;

	i = 0;
	j = 0;
	while (i < map->count)
	{
		str = map->map[i][0];
		if (str != '1')
			error(2);
		str = map->map[i][map->row_count - 1];
		if (str != '1')
			error(2);
		i++;
	}
	return (1);
}
