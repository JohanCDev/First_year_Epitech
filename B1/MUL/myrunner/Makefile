##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		sources/

SRC     =       $(DIR)main.c \
				$(DIR)create.c \
				$(DIR)destroy.c \
				$(DIR)initialize_project.c \
				$(DIR)game.c \
				$(DIR)animations.c \
				$(DIR)display.c \
				$(DIR)jump.c \
				$(DIR)create_file.c \
				$(DIR)finish_game.c \
				$(DIR)helper.c \
				$(DIR)obstacles.c \
				$(DIR)init_linked_list.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_runner

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

CC		=		gcc

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/my -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-system

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all