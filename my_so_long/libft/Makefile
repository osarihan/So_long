NAME := libft.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror

HEADER := libft.h

SRCS := 	ft_isalnum.c	ft_isprint.c	ft_memcpy.c	ft_putendl_fd.c	ft_strchr.c	ft_strlcat.c	ft_strncmp.c	ft_substr.c\
	ft_atoi.c	ft_isalpha.c	ft_itoa.c	ft_memmove.c	ft_putnbr_fd.c	ft_strdup.c	ft_strlcpy.c	ft_strnstr.c	ft_tolower.c\
	ft_bzero.c	ft_isascii.c	ft_memchr.c	ft_memset.c	ft_putstr_fd.c	ft_striteri.c	ft_strlen.c	ft_strrchr.c	ft_toupper.c\
	ft_calloc.c	ft_isdigit.c	ft_memcmp.c	ft_putchar_fd.c	ft_split.c	ft_strjoin.c	ft_strmapi.c	ft_strtrim.c

OBJECTS := $(SRCS:.c=.o)

BONUS_S =	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c	ft_lstdelone.c	ft_lstiter.c	ft_lstlast.c	ft_lstmap.c\
	ft_lstnew.c	ft_lstsize.c

BONUS_O = $(BONUS_S:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar -rcs $(NAME) $(OBJECTS)

bonus: $(NAME) $(BONUS_O)
	@ar -rcs $(NAME) $(BONUS_O)

clean:
	@rm -rf $(OBJECTS) $(BONUS_O)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

rebonus: fclean bonus

.PHONY:	all clean fclean re bonus rebonus
