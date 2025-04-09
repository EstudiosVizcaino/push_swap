# Makefile

NAME = push_swap

SRC = src/*.c src/utils/*.c libft/*.c
CC = cc
CFLAGS = -g

all:
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)
