/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:13:23 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/26 13:07:22 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int er)
{
	write (2, "Error\n", 7);
	if (er == 1)
		write(1, "Fazla ya da Eksik Argüman\n", 28);
	else if (er == 2)
		write(1, "Hatalı Map Dosyası!\n", 23);
	else if (er == 3)
		write(1, "Haritada Karakter ya da Çıkış ya da coin yok\n", 50);
	else if (er == 4)
		write(1, "Map Dikdörtgen Değil!\n", 25);
	exit(1);
}

int	destroy(void)
{
	write(1, "bb:*\n", 5);
	exit(1);
	return (0);
}

void	name_check(char **argv)
{
	char	*str;
	char	*str2;
	int		i;

	str2 = ".ber";
	i = 0;
	str = malloc(sizeof(char *) * 4);
	str = ft_strchr(argv[1], '.');
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == str2[i])
				i++;
			else
			{
				write(1, "Error\n.ber degil\n", 18);
				exit(0);
			}				
		}
	}
	else
	{
		return ;
	}		
}

void	move_msg(t_maps *map)
{
	char	*c;

	c = ft_itoa(map->step);
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("step:", 1);
	ft_putstr_fd(c, 1);
	ft_putstr_fd("\n", 1);
}
