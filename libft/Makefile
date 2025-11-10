CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_*.c
OBJS = $(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all