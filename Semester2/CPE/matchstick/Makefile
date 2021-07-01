##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c 						\
				$(DIR)print_game_board.c   			\
				$(DIR)player_turn.c 				\
				$(DIR)play_game.c 					\
				$(DIR)computer_turn.c 				\
				$(DIR)initialize.c 					\
				$(DIR)free_all.c 					\
				$(DIR)verify_inputs.c 				\

OBJ     =       $(SRC:.c=.o)

CC		=		gcc

NAME    =       matchstick

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy -lm -g

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my/

re:             fclean all