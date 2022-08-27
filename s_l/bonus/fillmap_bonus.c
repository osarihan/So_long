/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:24 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 17:11:32 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			move_msg2(map);
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
	m->move += 1;
	if (m->map[m->i][m->j] == '1')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->wall, m->j * 16, m->i * 16);
	else if (m->map[m->i][m->j] == '0')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->ground, m->j * 16, m->i * 16);
	else if (m->map[m->i][m->j] == 'C' || m->map[m->i][m->j] == 'P')
	{
		if (m->map[m->i][m->j] == 'C')
			put_img4(m, 'C');
		else if (m->map[m->i][m->j] == 'P')
			put_img4(m, 'P');
	}
	else if (m->map[m->i][m->j] == 'E')
	{
		put_img2(m, 'E');
	}
	else if (m->map[m->i][m->j] == 'F')
	{
		put_img3(m, 'F');
	}
}

void	put_img2(t_maps *m, int key)
{
	if (key == 'E')
	{
		if (m->coin_count == m->first_coin_count)
		{
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->ground, m->j * 16, m->i * 16);
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->exit2, m->j * 16, m->i * 16);
		}
		else
		{
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->ground, m->j * 16, m->i * 16);
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->exit, m->j * 16, m->i * 16);
		}
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
	m->foe = mlx_xpm_file_to_image(m->mlx_ptr, IMG_FOE, m->xx, m->yy);
	m->foe2 = mlx_xpm_file_to_image(m->mlx_ptr, IMG_FOE2, m->xx, m->yy);
	m->exit2 = mlx_xpm_file_to_image(m->mlx_ptr, IMG_EXIT2, m->xx, m->yy);
	m->hero2 = mlx_xpm_file_to_image(m->mlx_ptr, IMG_PLAYER2, m->xx, m->yy);
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
