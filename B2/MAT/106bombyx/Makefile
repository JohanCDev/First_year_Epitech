##
## EPITECH PROJECT, 2021
## B-MAT-100-NAN-1-1-105torus-johan.chrillesen
## File description:
## Makefile
##

SRC_DIR		=		src/

SRC			=		$(SRC_DIR)main.c \

OBJ			=		$(SRC:.c=.o)

NAME		=		106bombyx

CFLAGS		=		-Wall -Wshadow -Wextra -I./include

CC			=		gcc

all:				$(NAME)

$(NAME):			$(OBJ)
					make re -C lib/my/
					$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/my -lmy -lm

clean:
					rm -f $(OBJ)
					make clean -C lib/my/

fclean:				clean
					rm -rf $(NAME)
					make fclean -C lib/my/

re:					fclean all clean