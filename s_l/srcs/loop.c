/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:01:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 13:41:25 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_img(t_maps map)
{
	mlx_loop_hook (map.mlx_ptr, &fill_map, &map);
	mlx_hook (map.win_ptr, 2, 1L << 0, &key_press, &map);
	mlx_hook (map.win_ptr, 17, 0L, &destroy, &map);
	mlx_loop (map.mlx_ptr);
}
