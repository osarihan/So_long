/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:24 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/21 17:31:50 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_utils *utils, t_maps *map)
{
	int	asd;

	asd = map->count;
	utils->i = 0;
	utils->j = 0;
	init_xpms(utils, map);
	while (asd > 0)
	{	
		while (map->map[utils->i][utils->j] != '\0')
		{
			put_image(utils, map);
			utils->j++;
		}
		utils->j = 0;
		asd--;
		utils->i++;
	}
}

void	put_image(t_utils *u, t_maps *m)
{
	if (m->map[u->i][u->j] == '1')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->wall, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == '0')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->ground, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == 'C')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->coin, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == 'P')
	{
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, u->ground, u->j * 16, u->i * 16);
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
