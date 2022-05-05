CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = calculate.c operate.c main.c print.c
OBJS = $(SRCS:.c=.o)
NAME = do-op

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
