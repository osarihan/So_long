/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:24 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/22 04:16:51 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_map(t_utils *utils, t_maps *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	utils->i = 0;
	utils->j = 0;
	map->count = map->count;
	printf("map_count:%d\n", map->count);
	while (map->map[i][j] != '\0')
	{	
		while (map->map[utils->i][utils->j] != '\0')
		{
			put_image(utils, map);
			utils->j++;
		}
		utils->j = 0;
		utils->i++;
		j++;
		i++;
	}
	return(0);
}

void	put_image(t_utils *u, t_maps *m)
{
	if (m->map[u->i][u->j] == '1')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->wall, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == '0')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->ground, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == 'C' || m->map[u->i][u->j] == 'P')
	{
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->ground, u->j * 16, u->i * 16);
		if (m->map[u->i][u->j] == 'C')
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, u->coin, u->j * 16, u->i * 16);
		else
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, u->hero, u->j * 16, u->i * 16);
	}
	else if (m->map[u->i][u->j] == 'E')
	{
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->ground, u->j * 16, u->i * 16);
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->exit, u->j * 16, u->i * 16);
	}	
}

void	init_xpms(t_utils *utils, t_maps *map)
{
	int	*xx;
	int	*yy;
	int	x;
	int	y;

	x = 16;
	y = 16;
	xx = &x;
	yy = &y;
	utils->wall = mlx_xpm_file_to_image(map->mlx_ptr, IMG_WALL, xx, yy);
	utils->hero = mlx_xpm_file_to_image(map->mlx_ptr, IMG_PLAYER, xx, yy);
	utils->coin = mlx_xpm_file_to_image(map->mlx_ptr, IMG_COIN, xx, yy);
	utils->exit = mlx_xpm_file_to_image(map->mlx_ptr, IMG_EXIT, xx, yy);
	utils->ground = mlx_xpm_file_to_image(map->mlx_ptr, IMG_GROUND, xx, yy);
}

void	find_player(t_maps *map)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	printf("Mapfimdcount:%d\n", map->count);
	while(i < map->count)
	{
		while(map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->playerx = j;
				map->playery = i;
			}
			j++;
		}
		i++;
	}	
}