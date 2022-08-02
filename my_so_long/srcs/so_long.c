/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:58:21 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/01 14:26:48 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	utils *utils;

	void *mlx;
	int *map;
	if (argc == 2)
	{
		map = map_check(map, argv, &utils);
		mlx = mlx_call(500, 500);
		mlx_loop(mlx);
	}
	else
		error();
}
