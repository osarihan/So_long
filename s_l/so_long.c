/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:58:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/22 04:07:17 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_utils		*utils;
	t_maps		*map;

	utils = malloc(sizeof(t_utils));
	map = malloc(sizeof(t_maps));
	if (argc == 2)
	{
		create_map(argv, map);
		if (check_map(map) != 1)
			error();
		call_mlx(map);
		init_xpms(utils, map);
		//fill_map(utils, map);
		find_player(map);
		printf("map_count:%d\n", map->count);
		loop_img(utils, map);
		printf("d\n");
	}
	else
		error();
}
