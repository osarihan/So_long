/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:01:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 17:39:26 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	loop_img(t_maps map)
{
	mlx_loop_hook (map.mlx_ptr, &fill_map, &map);
	mlx_hook (map.win_ptr, 2, 1L << 0, &key_press, &map);
	mlx_hook (map.win_ptr, 17, 0L, &destroy, &map);
	mlx_clear_window(map.mlx_ptr, map.win_ptr);
	mlx_loop (map.mlx_ptr);
}
