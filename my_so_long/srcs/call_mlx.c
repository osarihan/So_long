/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxcall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:59:54 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/18 16:30:45 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*call_mlx(unsigned int height, unsigned int weight)
{
	void	*init;
	void	*window;

	init = mlx_init();
	window = mlx_new_window(init, height, weight, "so_long");
	return (init);
}
