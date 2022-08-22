/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:01:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/22 04:16:01 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_img(t_utils *utils, t_maps *map)
{
	printf("map_count:%d\n", map->count);
	printf("D\n");
	mlx_loop_hook(map->mlx_ptr, &fill_map, map);
	printf("map_count:%d\n", map->count);
	printf("E\n");
	mlx_hook(map->win_ptr, 2, 1L<<0, &key_press, map);
	printf("map_count:%d\n", map->count);
	printf("F\n");
	mlx_loop(map->mlx_ptr);
}
