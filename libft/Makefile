CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
DEPENDENCIES = ft_*.o


$(TARGET):  $(DEPENDENCIES)
	ar rcs $(TARGET) $(DEPENDENCIES)

$(DEPENDENCIES): ft_*.c
	$(CC) $(CFLAGS) -c ft_*.c

clean:
	rm -f *.o 
