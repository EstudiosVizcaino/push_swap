# Makefile

NAME = push_swap

SRC = src/*.c src/utils/*.c libft/*.c src/ops/*.c
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

all:
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)
