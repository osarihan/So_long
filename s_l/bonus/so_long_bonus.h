/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:38 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 18:09:33 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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
	void					*win_ptr;
	void					*mlx_ptr;
	char					**map;
	void					*foe;
	void					*ground;
	void					*hero;
	void					*wall;
	void					*coin;
	void					*exit;
	void					*foe2;
	void					*exit2;
	void					*hero2;
	int						*xx;
	int						*yy;
	int						i;
	int						j;
	int						fd;
	int						count;
	int						row_count;
	int						playerx;
	int						playery;
	int						s_count;
	int						first_coin_count;
	int						coin_count;
	int						step;
	int						can_exit;
	unsigned long int		move;
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
void	move_msg2(t_maps *map);
void	put_img2(t_maps *m, int key);
void	put_img3(t_maps *m, int key);
void	put_img4(t_maps *m, int key);
///////////////////////////////////////////////
# define ESC 53
# define W	 13
# define A	 0
# define S	 1
# define D	 2
///////////////////////////////////////////////
# define IMG_WALL "./xpms/1_wall.xpm"
# define IMG_GROUND "./xpms/0_wall.xpm"
# define IMG_PLAYER "./xpms/balcik01.xpm"
# define IMG_PLAYER2 "./xpms/balcik02.xpm"
# define IMG_EXIT "./xpms/kapalilapi.xpm"
# define IMG_EXIT2 "./xpms/acikkapi.xpm"
# define IMG_COIN "./xpms/coin.xpm"
# define IMG_FOE "./xpms/foe_1.xpm"
# define IMG_FOE2 "./xpms/foe_2.xpm"

#endif