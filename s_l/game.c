/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:24 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/21 17:01:12 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_utils *utils, void *mlx_ptr, void *wdw_ptr, t_maps *map)
{
	int	asd;

	asd = map->count;
	utils->i = 0;
	utils->j = 0;
	init_xpms(utils, mlx_ptr);
	while (asd > 0)
	{	
		while (map->map[utils->i][utils->j] != '\0')
		{
			put_image(mlx_ptr, wdw_ptr, utils, map);
			utils->j++;
		}
		utils->j = 0;
		asd--;
		utils->i++;
	}
}

void	put_image(void *mlx, void *wdw, t_utils *u, t_maps *m)
{
	if (m->map[u->i][u->j] == '1')
		mlx_put_image_to_window(mlx, \
			wdw, u->wall, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == '0')
		mlx_put_image_to_window(mlx, \
			wdw, u->ground, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == 'C')
		mlx_put_image_to_window(mlx, \
			wdw, u->coin, u->j * 16, u->i * 16);
	else if (m->map[u->i][u->j] == 'P')
	{
		mlx_put_image_to_window(mlx, \
			wdw, u->ground, u->j * 16, u->i * 16);
		mlx_put_image_to_window(mlx, \
			wdw, u->hero, u->j * 16, u->i * 16);
	}
	else if (m->map[u->i][u->j] == 'E')
	{
		mlx_put_image_to_window(mlx, \
			wdw, u->ground, u->j * 16, u->i * 16);
		mlx_put_image_to_window(mlx, \
			wdw, u->exit, u->j * 16, u->i * 16);
	}	
}

void	init_xpms(t_utils *utils, void *mlx_ptr)
{
	int	*xx;
	int	*yy;
	int	x;
	int	y;

	x = 16;
	y = 16;
	xx = &x;
	yy = &y;
	utils->wall = mlx_xpm_file_to_image(mlx_ptr, IMG_WALL, xx, yy);
	utils->hero = mlx_xpm_file_to_image(mlx_ptr, IMG_PLAYER, xx, yy);
	utils->coin = mlx_xpm_file_to_image(mlx_ptr, IMG_COIN, xx, yy);
	utils->exit = mlx_xpm_file_to_image(mlx_ptr, IMG_EXIT, xx, yy);
	utils->ground = mlx_xpm_file_to_image(mlx_ptr, IMG_GROUND, xx, yy);
}
