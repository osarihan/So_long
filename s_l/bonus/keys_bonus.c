/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:55:14 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 18:06:51 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	d_handler(t_maps *map, int key)
{
	if (key == D)
	{
		if (map->map[map->playery][map->playerx + 1] == '1')
			return (0);
		else if (map->map[map->playery][map->playerx + 1] == 'C')
			coin(map);
		else if (map->map[map->playery][map->playerx + 1] == 'E')
		{
			if (can_exit(map) == 1)
			{
				write(1, "You are super player\n", 22);
				exit(0);
			}
			else
				return (0);
		}
		else if (map->map[map->playery][map->playerx + 1] == 'F')
		{
			write(1, "gg!\n", 4);
			exit(0);
		}
	}
	return (1);
}

int	s_handler(t_maps *map, int key)
{
	if (key == S)
	{
		if (map->map[map->playery + 1][map->playerx] == '1')
			return (0);
		else if (map->map[map->playery + 1][map->playerx] == 'C')
			coin(map);
		else if (map->map[map->playery + 1][map->playerx] == 'E')
		{
			if (can_exit(map) == 1)
			{
				write(1, "You are super player\n", 22);
				exit(0);
			}
			else
				return (0);
		}
		else if (map->map[map->playery + 1][map->playerx] == 'F')
		{
			write(1, "gg!\n", 4);
			exit(0);
		}
	}
	return (1);
}

int	w_handler(t_maps *map, int key)
{
	if (key == W)
	{
		if (map->map[map->playery - 1][map->playerx] == '1')
			return (0);
		else if (map->map[map->playery - 1][map->playerx] == 'C')
			coin (map);
		else if (map->map[map->playery - 1][map->playerx] == 'E')
		{
			if (can_exit(map) == 1)
			{
				write(1, "You are super player\n", 22);
				exit(0);
			}
			else
				return (0);
		}
		else if (map->map[map->playery - 1][map->playerx] == 'F')
		{
			write(1, "bb\n", 3);
			exit(0);
		}
	}
	return (1);
}

int	a_handler(t_maps *map, int key)
{
	if (key == A)
	{
		if (map->map[map->playery][map->playerx - 1] == '1')
			return (0);
		else if (map->map[map->playery][map->playerx - 1] == 'C')
			coin(map);
		else if (map->map[map->playery][map->playerx - 1] == 'E')
		{
			if (can_exit(map) == 1)
			{
				write(1, "You are super player\n", 22);
				exit(0);
			}
			else
				return (0);
		}
		else if (map->map[map->playery][map->playerx - 1] == 'F')
		{
			write(1, "gg!\n", 4);
			exit(0);
		}
	}
	return (1);
}

int	can_exit(t_maps *map)
{
	if (map->coin_count == map->first_coin_count)
	{
		return (1);
		map->can_exit = 1;
	}
	else
		return (0);
}
