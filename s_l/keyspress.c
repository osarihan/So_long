/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyspress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:06:32 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/23 16:25:56 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	can_move(t_maps *map, int key)
{
	if (key == D)
	{
		if	(!D_handler(map, key))
			return(0);
	}
	else if(key == A)
	{
		if	(!A_handler(map, key))
			return(0);
	}
	else if(key == S)
	{
		if	(!S_handler(map, key))
			return(0);
	}
	else if(key == W)
	{
		if	(!W_handler(map, key))
			return(0);
	}
	return(1);
}

void	move_player(t_maps *map, int key)
{
	if (key == A)
		map->playerx--;
	else if (key == W)
		map->playery--;
	else if (key == S)
		map->playery++;
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
		map->map[map->playery][map->playerx] = 'P';
	}

	return(1);
}


int	handle_btn(t_maps *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	ft_putstr_fd("kapandi\n", 1);
	exit(0);
	return (0);
}

void	coin(t_maps *map)
{
	map->coin_count++;
}