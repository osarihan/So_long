/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:38 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/20 14:52:42 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct game_utils
{
	int	empty_wall;
	int	hero;
	int	wall;
	int	coin;
	int	exit;
}	t_utils;

typedef struct map_utils
{
	char	**map;
	int		fd;
	int		count;
	int		row_count;
}	t_maps;

//GNL UTILS
char	*get_next_line(int fd);
char	*ft_read_line(char *src);
char	*ft_save(char *src);
char	*get_line(char *src, int fd);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(char *s);
char	*ft_strchr1(char *src, int c);
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

#endif