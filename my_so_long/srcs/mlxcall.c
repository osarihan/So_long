/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxcall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:59:54 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/01 14:03:07 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *init;
void *window;

void *mlx_call(unsigned int height, unsigned int weight)
{
	init = mlx_init();
	window = mlx_new_window(init, height, weight, "so_long");
	return(init);
}
