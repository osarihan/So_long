# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:29:30 by osarihan          #+#    #+#              #
#    Updated: 2022/08/27 17:17:30 by osarihan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb -Wall -Wextra -Werror
NAME = so_long
NAME2 = so_long_bonus
SRC = srcs/*.c libft/*.c GNL/*.c
BONUS_SRC = bonus/*.c libft/*.c GNL/*.c

all:
	@make -C libft
	$(CC) $(SRC)  $(FLAGS) -o $(NAME)

clean:
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@make fclean -C libft

norm:
	@norminette libft srcs GNL bonus

bonus:
	@make -C libft
	$(CC) $(BONUS_SRC) $(FLAGS) -o $(NAME2)

bonusclean:
	@make clean -C libft

bonusfclean: clean
	@rm -rf $(NAME2)
	@rm -rf $(NAME2).dSYM
	@make fclean -C libft

re: fclean all

rebonus: bonusfclean bonus

.PHONY: all clean fclean norm re bonus bonusclean bonusfclean rebonus
