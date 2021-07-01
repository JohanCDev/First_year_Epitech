##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)check_placements.c \
				$(DIR)create_map.c \
				$(DIR)boats.c \
				$(DIR)init_boats.c \
				$(DIR)signals.c \
				$(DIR)connect.c \
				$(DIR)files.c \
				$(DIR)play.c \
				$(DIR)change_maps.c \
				$(DIR)end_game.c \

OBJ     =       $(SRC:.c=.o)

CC		=		gcc

NAME    =       navy

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my/

re:             fclean all