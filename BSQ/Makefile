CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCS = main.c ft_split.c make_map.c find_square.c fill.c ft_atoi.c
OBJS = $(SRCS:.c=.o)

.PHONY : clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
