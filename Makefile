# # Makefile

# NAME = push_swap

# SRC = src/*.c src/utils/*.c libft/*.c src/ops/*.c
# CC = cc
# CFLAGS = -Wall -Werror -Wextra -g3

# all:
# 	$(CC) $(SRC) $(CFLAGS) -o $(NAME)


NAME				= push_swap

LIBFT				= libft/libft.a
SRC_DIR				= src/
OBJ_DIR				= src/obj/


CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g3
RM					= rm -f

UTILS_DIR		= $(wildcard $(SRC_DIR)utils/*.c)

COMMANDS_DIR	= $(wildcard $(SRC_DIR)ops/swap.c \
					$(SRC_DIR)ops/rev_rotate.c \
					$(SRC_DIR)ops/rotate.c \
					$(SRC_DIR)ops/push.c)

ALGORITHM_DIR	= $(wildcard $(SRC_DIR)ops/ksort.c \
					$(SRC_DIR)ops/small_sorts.c)

PUSH_SWAP_DIR	= $(wildcard $(SRC_DIR)push_swap.c)


SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR) $(ALGORITHM_DIR) $(UTILS_DIR) 

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re bonus