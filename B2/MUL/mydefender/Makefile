##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)animations/events.c \
				$(DIR)animations/events_switch.c \
				$(DIR)animations/get.c \
				$(DIR)animations/rect.c \
				$(DIR)animations/wave_chrono.c \
				$(DIR)animations/window.c \
				$(DIR)buttons/button.c \
				$(DIR)buttons/button_is_clicked.c \
				$(DIR)create_and_destroy/create_button.c \
				$(DIR)create_and_destroy/create_object.c \
				$(DIR)create_and_destroy/create_towers.c \
				$(DIR)create_and_destroy/destroy.c \
				$(DIR)create_and_destroy/enemies_list.c \
				$(DIR)create_and_destroy/remove_enemy.c \
				$(DIR)initialize/initialize_all.c \
				$(DIR)initialize/initialize_menus.c \
				$(DIR)initialize/initialize_playing_game.c \
				$(DIR)initialize/initialize_scoreboard.c \
				$(DIR)initialize/initialize_texts.c \
				$(DIR)initialize/reinitialize_all.c \
				$(DIR)towers/detect_purchase.c \
				$(DIR)towers/buy_towers.c \
				$(DIR)towers/market_tower.c \
				$(DIR)towers/show_tower.c \
				$(DIR)towers/tower_interact_enemies.c \
				$(DIR)towers/towers.c \
				$(DIR)image.c \
				$(DIR)waves.c \
				$(DIR)differents_enemies.c \
				$(DIR)update_text.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_defender

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

LDFLAGS =		-L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all

debug:			CFLAGS += -g
debug:			re