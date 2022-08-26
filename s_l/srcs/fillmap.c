/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:24 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/25 17:43:17 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_map(t_maps *map)
{
	int	asd;

	asd = map->count;
	map->i = 0;
	map->j = 0;
	while (asd > 0)
	{	
		while (map->map[map->i][map->j] != '\0')
		{
			put_image(map);
			map->j++;
		}
		map->j = 0;
		map->i++;
		asd--;
	}
	return (0);
}

void	put_image(t_maps *m)
{
	if (m->map[m->i][m->j] == '1')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->wall, m->j * 16, m->i * 16);
	else if (m->map[m->i][m->j] == '0')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->ground, m->j * 16, m->i * 16);
	else if (m->map[m->i][m->j] == 'C' || m->map[m->i][m->j] == 'P')
	{
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->ground, m->j * 16, m->i * 16);
		if (m->map[m->i][m->j] == 'C')
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->coin, m->j * 16, m->i * 16);
		else
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->hero, m->j * 16, m->i * 16);
	}
	else if (m->map[m->i][m->j] == 'E')
	{
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->ground, m->j * 16, m->i * 16);
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->exit, m->j * 16, m->i * 16);
	}	
}

void	init_xpms(t_maps *m)
{
	int	x;
	int	y;

	x = 16;
	y = 16;
	m->xx = &x;
	m->yy = &y;
	m->wall = mlx_xpm_file_to_image(m->mlx_ptr, IMG_WALL, m->xx, m->yy);
	m->hero = mlx_xpm_file_to_image(m->mlx_ptr, IMG_PLAYER, m->xx, m->yy);
	m->coin = mlx_xpm_file_to_image(m->mlx_ptr, IMG_COIN, m->xx, m->yy);
	m->exit = mlx_xpm_file_to_image(m->mlx_ptr, IMG_EXIT, m->xx, m->yy);
	m->ground = mlx_xpm_file_to_image(m->mlx_ptr, IMG_GROUND, m->xx, m->yy);
}

void	find_player(t_maps *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->first_coin_count = 0;
	while (i < map->count)
	{
		while (map->map[i][j] != '\0')
		{	
			if (map->map[i][j] == 'P')
			{
				map->playerx = j;
				map->playery = i;
			}
			else if (map->map[i][j] == 'C')
				map->first_coin_count++;
			j++;
		}
		j = 0;
		i++;
	}	
}
