# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:29:30 by osarihan          #+#    #+#              #
#    Updated: 2022/08/17 16:26:10 by osarihan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L../minilibx -lmlx -glldb
NAME = so_long
SRC = *.c

all:
	$(CC) $(SRC) -o $(NAME) $(FLAGS)

kill:
	@rm -rf so_long