CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = main.c push_swap.c push_swap_utils.c push_swap_ops.c push_swap_ops2.c push_swap_ops3.c chunk_sort.c check_args.c ft_split.c ft_substr.c list_helpers.c list_helpers2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: re
	./mactest.sh

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test