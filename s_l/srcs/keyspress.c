/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyspress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:06:32 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 18:14:16 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_maps *map, int key)
{
	if (key == D)
	{
		if (!d_handler(map, key))
			return (0);
		map->step++;
	}
	else if (key == A)
	{
		if (!a_handler(map, key))
			return (0);
		map->step++;
	}
	else if (key == S)
	{
		if (!s_handler(map, key))
			return (0);
		map->step++;
	}
	else if (key == W)
	{
		if (!w_handler(map, key))
			return (0);
		map->step++;
	}
	return (1);
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
	char	*c;

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
		c = ft_itoa(map->step);
		move_msg(map);
		free(c);
	}
	return (1);
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
