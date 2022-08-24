# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:29:30 by osarihan          #+#    #+#              #
#    Updated: 2022/08/24 16:07:56 by osarihan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb -Wall -Wextra -Werror
NAME = so_long
SRC = *.c libft/*.c GNL/*.c

all:
	$(CC) $(SRC) -o $(NAME) $(FLAGS)
fclean: clean
	@rm -rf so_long
