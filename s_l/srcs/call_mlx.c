/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:59:54 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/25 12:24:26 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ne_is_lazimsa(t_maps *map)
{
	map->i = 0;
	map->step = 0;
	map->playerx = 0;
	map->playery = 0;
	map->s_count = 0;
	map->first_coin_count = 0;
	map->coin_count = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, \
		map->row_count * 16, map->count * 16, "so_long");
}
