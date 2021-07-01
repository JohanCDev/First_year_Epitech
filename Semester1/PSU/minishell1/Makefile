##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)builtins/change_dir.c \
				$(DIR)builtins/change_dir_two.c \
				$(DIR)builtins/manage_env/set_env.c \
				$(DIR)builtins/manage_env/set_env_two.c \
				$(DIR)builtins/manage_env/unset_env.c \
				$(DIR)initialization/initialize_project.c \
				$(DIR)initialization/get_path.c \
				$(DIR)main.c \
				$(DIR)print_info_fail.c \
				$(DIR)commands.c \
				$(DIR)do_others.c \
				$(DIR)do_others_two.c \
				$(DIR)helpers.c \
				$(DIR)start_loop.c \
				$(DIR)free.c \

OBJ     =       $(SRC:.c=.o)

CC		=		gcc

NAME    =       mysh

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