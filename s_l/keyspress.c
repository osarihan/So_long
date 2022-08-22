/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyspress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:06:32 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/22 03:35:49 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	can_move(t_maps *map, int key)
{
	if (key == D)
	{
		if (map->map[map->playerx + 1][map->playery] == '1' \
			|| map->map[map->playerx + 1][map->playery] == 'C')
			return(0);
	}
	else if(key == A)
	{
		if (map->map[map->playerx - 1][map->playery] == '1'\
			|| map->map[map->playerx - 1][map->playery] == 'C')
			return(0);
	}
	else if(key == S)
	{
		if (map->map[map->playerx][map->playery - 1] == '1'\
			|| map->map[map->playerx][map->playery - 1] == 'C')
			return(0);
	}
	else if(key == W)
	{
		if (map->map[map->playerx][map->playery + 1] == '1'\
			|| map->map[map->playerx][map->playery + 1] == 'C')
			return(0);
	}
	else
		return(1);
	return(0);
}

void	move_player(t_maps *map, int key)
{
	if (key == A)
		map->playerx--;
	else if (key == W)
		map->playery++;
	else if (key == S)
		map->playery--;
	else if (key == D)
		map->playerx++;
}

int	key_press(int key, t_maps *map)
{
	if (key == ESC)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		ft_putstr_fd("kapandi\n", 1);
		exit(0);
	}
	if (can_move(map, key) == 1)
	{
		map->map[map->playery][map->playerx] = '0';
		move_player(map, key);
	}
	return(0);
}


int	handle_btn(t_maps *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	ft_putstr_fd("kapandi\n", 1);
	exit(0);
	return (0);
}
