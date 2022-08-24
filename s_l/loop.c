/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:01:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/24 17:38:08 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_img(t_maps map)
{
	mlx_loop_hook (map.mlx_ptr, &fill_map, &map);
	mlx_hook (map.win_ptr, 2, 1L << 0, &key_press, &map);
	mlx_hook (map.win_ptr, 17, 0L, &key_press, &map);
	mlx_loop (map.mlx_ptr);
}

void	destroy_img(t_maps *map)
{
	mlx_destroy_image(map->mlx_ptr, map->wall);
	mlx_destroy_image(map->mlx_ptr, map->ground);
	mlx_destroy_image(map->mlx_ptr, map->hero);
	mlx_destroy_image(map->mlx_ptr, map->exit);
	mlx_destroy_image(map->mlx_ptr, map->coin);
}
