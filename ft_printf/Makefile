CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_format_handle.c ft_print_c.c ft_print_s.c \
	ft_print_ptr.c ft_print_int.c ft_print_uint.c ft_print_itox.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

test: re
	$(CC) ../print_test.c -L. -lftprintf -o ../result
	../result

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test