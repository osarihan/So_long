/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:58:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/21 17:03:39 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_utils		*utils;
	t_maps		*map;
	void		*mlx_ptr;
	void		*window_ptr;

	utils = malloc(sizeof(t_utils));
	map = malloc(sizeof(t_maps));
	if (argc == 2)
	{
		create_map(argv, map);
		if (check_map(map) != 1)
			error();
		mlx_ptr = mlx_init();
		window_ptr = mlx_new_window(mlx_ptr, \
			(map->row_count * 16), (map->count * 16), "so_long");
		fill_map(utils, mlx_ptr, window_ptr, map);
		mlx_loop(mlx_ptr);
	}
	else
		error();
}
