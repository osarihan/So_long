# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:29:30 by osarihan          #+#    #+#              #
#    Updated: 2022/08/25 15:45:20 by osarihan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb -Wall -Wextra -Werror
NAME = so_long
SRC = srcs/*.c libft/*.c GNL/*.c

all:
	$(CC) $(SRC) -o $(NAME) $(FLAGS)
clean:
	@rm -rf libft.a
fclean: clean
	@rm -rf so_long
norm:
	@norminette libft srcs GNL
re: fclean all
