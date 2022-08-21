/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:38 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/21 17:03:02 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "GNL/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct game_utils
{
	void	*ground;
	void	*hero;
	void	*wall;
	void	*coin;
	void	*exit;
	int		i;
	int		j;
}	t_utils;

typedef struct map_utils
{
	char	**map;
	int		fd;
	int		count;
	int		row_count;
}	t_maps;

//
void	*call_mlx(unsigned int height, unsigned int weight);
void	error(void);
//MAP UTILS
int		line_count(char **argv);
void	create_map(char **argv, t_maps *read);
int		check_map(t_maps *map);
int		check_map_lenght(t_maps *map);
int		check_map_utils(t_maps *map);
int		utils_count(char *str, char c);
int		check_map_rows(t_maps *map);
int		check_map_columns(t_maps *map);
void	init_xpms(t_utils *utils, void *mlx_ptr);
void	fill_map(t_utils *utils, void *mlx_ptr, void *wdw_ptr, t_maps *map);
//MLX FUNCS
void	put_image(void *mlx, void *wdw, t_utils *u, t_maps *m);
//KEYS
# define ESC 53
# define W	 13
# define A	 0
# define S	 1
# define D	 2
//PATHS
# define IMG_SIZE 32
# define IMG_WALL "./xpms/1_wall.xpm"
# define IMG_GROUND "./xpms/0_wall.xpm"
# define IMG_PLAYER "./xpms/knight.xpm"
# define IMG_EXIT "./xpms/closed_door.xpm"
# define IMG_COIN "./xpms/coin.xpm"
# define IMG_FOE "./xpms/foe.xpm"

#endif