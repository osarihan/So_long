/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:58:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/24 17:06:18 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps		map;

	if (argc == 2)
	{
		create_map(argv[1], &map);
		printf("asdf\n");
		if (check_map(&map) != 1)
			error();
		ne_is_lazimsa(&map);
		init_xpms(&map);
		fill_map(&map);
		find_player(&map);
		loop_img(map);
		exit(0);
	}
	else
	{
		free(&map);
		error();
	}
}
