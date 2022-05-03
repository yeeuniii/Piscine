CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = $(addprefix srcs/,$(SRC))
#SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
#OBJS = $(SRCS:.c=.o)
INCLUDE = includes
NAME = libft.a

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUDE)

$(NAME) : $(OBJS)
	ar rc $@ $^

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re 
