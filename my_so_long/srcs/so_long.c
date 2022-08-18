/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:58:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/18 16:58:01 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_utils		*utils;
	t_maps		*map;
	void		*mlx;

	utils = malloc(sizeof(t_utils));
	map = malloc(sizeof(t_maps));
	if (argc == 2)
	{
		create_map(argv, map);
		if (check_map(map) != 1)
			error();
	}
	else
		error();
}
