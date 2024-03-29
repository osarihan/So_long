/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:38 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 13:41:32 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
///////////////////////////////////////////////
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../GNL/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
///////////////////////////////////////////////
///////////////////////////////////////////////
typedef struct map_utils
{
	int		i;
	int		j;
	void	*win_ptr;
	void	*mlx_ptr;
	char	**map;
	int		fd;
	int		count;
	int		row_count;
	int		playerx;
	int		playery;
	int		s_count;
	void	*ground;
	void	*hero;
	void	*wall;
	void	*coin;
	void	*exit;
	int		first_coin_count;
	int		coin_count;
	int		*xx;
	int		*yy;
	int		step;
}	t_maps;
///////////////////////////////////////////////
void	ne_is_lazimsa(t_maps *map);
void	error(int er);
///////////////////////////////////////////////
int		line_count(char **argv);
void	create_map(char *path, t_maps *map);
int		check_map(t_maps *map);
int		check_map_lenght(t_maps *map);
int		check_map_utils(t_maps *map);
int		utils_count(char *str, char c);
int		check_map_rows(t_maps *map);
int		check_map_columns(t_maps *map);
void	init_xpms(t_maps *map);
int		fill_map(t_maps *map);
void	put_image(t_maps *m);
///////////////////////////////////////////////
void	loop_img(t_maps map);
int		key_press(int key, t_maps *maps);
int		handle_btn(t_maps *map);
void	move_player(t_maps *map, int key);
int		can_move(t_maps *map, int key);
void	find_player(t_maps *map);
void	coin(t_maps *map);
///////////////////////////////////////////////
int		d_handler(t_maps *map, int key);
int		s_handler(t_maps *map, int key);
int		w_handler(t_maps *map, int key);
int		a_handler(t_maps *map, int key);
int		can_exit(t_maps *map);
int		destroy(void);
void	name_check(char **argv);
void	move_msg(t_maps *map);
void	utils_check(char *str);
///////////////////////////////////////////////
# define ESC 53
# define W	 13
# define A	 0
# define S	 1
# define D	 2
///////////////////////////////////////////////
# define IMG_WALL "./xpms/1_wall.xpm"
# define IMG_GROUND "./xpms/0_wall.xpm"
# define IMG_PLAYER "./xpms/knight.xpm"
# define IMG_EXIT "./xpms/closed_door.xpm"
# define IMG_COIN "./xpms/coin.xpm"
# define IMG_FOE "./xpms/foe.xpm"

#endif