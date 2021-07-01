##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c 								\
				$(DIR)initialize/initialize_game.c 			\
				$(DIR)initialize/initialize_menus.c 		\
				$(DIR)initialize/initialize_all.c 			\
				$(DIR)initialize/initialize_quest.c 		\
				$(DIR)initialize/initialize_other.c 		\
				$(DIR)initialize/initialize_fight.c 		\
				$(DIR)initialize/initialize_enemies.c 		\
				$(DIR)animations/events.c 					\
				$(DIR)animations/events_switch.c 			\
				$(DIR)animations/event_switch_utils.c 		\
				$(DIR)animations/window.c 					\
				$(DIR)animations/rect.c 					\
				$(DIR)animations/display.c 					\
				$(DIR)animations/analyse_events.c 					\
				$(DIR)create_and_destroy/create_button.c 	\
				$(DIR)create_and_destroy/create_enemies.c 	\
				$(DIR)create_and_destroy/create_object.c 	\
				$(DIR)create_and_destroy/destroy_others.c 	\
				$(DIR)create_and_destroy/destroy.c 			\
				$(DIR)create_and_destroy/remove_enemy.c 	\
				$(DIR)create_and_destroy/destroy_scene.c 	\
				$(DIR)create_and_destroy/destroy_musics_and_enemies.c 	\
				$(DIR)fight/fight_scene.c 					\
				$(DIR)fight/initialize_and_end_fight.c 		\
				$(DIR)fight/proceed_fight.c 				\
				$(DIR)fight/update_fight_scene.c 			\
				$(DIR)fight/display_boss_text.c 			\
				$(DIR)fight/make_fight.c 			\
				$(DIR)fight/visual_effect_fight.c 			\
				$(DIR)buttons/button_is_clicked.c 			\
				$(DIR)buttons/button.c 						\
				$(DIR)player/init_player.c 					\
				$(DIR)quests/check_travel_quests.c 			\
				$(DIR)quests/check_all_regions.c 			\
				$(DIR)tools/update_text.c					\
				$(DIR)inventory/inv_functions.c 			\
				$(DIR)inventory/inv_fct_utils.c 			\
				$(DIR)inventory/inv_display.c 				\
				$(DIR)inventory/init_travel_texts.c 		\
				$(DIR)particles/particles.c 				\
				$(DIR)particles/random.c 					\
				$(DIR)particles/snow.c 						\
				$(DIR)inventory/init_inv.c 					\
				$(DIR)reinitialize/reinitialize_all.c 		\
				$(DIR)reinitialize/reinitialize_quests.c 		\
				$(DIR)reinitialize/reset_inv.c 		\
				$(DIR)end_game/check_end.c 		\

OBJ     =       $(SRC:.c=.o)

NAME    =       my_rpg

END		=		\033[0m

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

LDFLAGS =		-L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window -lm -lcsfml-audio

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
				@echo -e "\033[32m=========(   RPG COMPLETED  )=========$(END)"

clean:
				rm -f $(OBJ)
				make clean -C lib/my/
				@echo -e "\033[31m=========(    RPG CLEANED   )=========$(END)"

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all

debug:			CFLAGS += -g
debug:			re