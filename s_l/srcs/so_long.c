/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:58:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/25 13:43:33 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps		map;

	if (argc == 2)
	{
		name_check(argv);
		create_map(argv[1], &map);
		if (check_map(&map) != 1)
			error(2);
		ne_is_lazimsa(&map);
		init_xpms(&map);
		fill_map(&map);
		find_player(&map);
		loop_img(map);
	}
	else
	{
		error(1);
	}
}
