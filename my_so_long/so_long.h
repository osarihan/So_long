/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:38 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/01 17:53:23 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h";
#include "Gnl/get_next_line.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct game_utils
{
	int	empty_wall;
	int	hero;
	int	wall;
	int	coin;
	int	exit;
} utils;

typedef struct map_utils
{
	char **map;
} maps;

void	*mlx_call(unsigned int height, unsigned int weight);
utils	*utils_count(char **argv, utils *count);
void	error();
//MAP UTILS
int		line_count(char **argv);
char 	**create_map(char **argv, maps *read);
int		*map_check(int *map, char **argv, utils *datas);
utils 	*utils_count(char **argv, utils *count);

#endif