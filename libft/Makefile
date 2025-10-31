CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = $@

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $@
