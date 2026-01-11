CC = gcc
CFLAGS = -Wall -Wextra -std=c99

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

run-%: %
	./$<

clean: 
	find . -type f -perm -111 ! -name "*.c" -delete

.PHONY: run clean
