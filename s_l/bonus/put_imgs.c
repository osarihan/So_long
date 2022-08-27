/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:05:58 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/27 17:12:27 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img3(t_maps *m, int key)
{
	if (key == 'F')
	{
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->ground, m->j * 16, m->i * 16);
		if (m->move % 13 == 0)
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->foe2, m->j * 16, m->i * 16);
		else
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->foe, m->j * 16, m->i * 16);
	}
}

void	put_img4(t_maps *m, int key)
{
	mlx_put_image_to_window(m->mlx_ptr, \
		m->win_ptr, m->ground, m->j * 16, m->i * 16);
	if (key == 'C')
		mlx_put_image_to_window(m->mlx_ptr, \
			m->win_ptr, m->coin, m->j * 16, m->i * 16);
	else
	{
		if (m->move % 13 == 0)
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->hero, m->j * 16, m->i * 16);
		else
			mlx_put_image_to_window(m->mlx_ptr, \
				m->win_ptr, m->hero2, m->j * 16, m->i * 16);
	}
}
