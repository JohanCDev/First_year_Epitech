##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)my_put_tab.c \
				$(DIR)make_list.c \
				$(DIR)rights.c \
				$(DIR)errors.c \
				$(DIR)switch_param.c \
				$(DIR)flag_l.c \
				$(DIR)swap_nodes.c \
				$(DIR)swap_alpha.c \
				$(DIR)swap_time.c \
				$(DIR)print_list.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_ls

CFLAGS  =       -Wall -Wshadow -Wextra -I./include

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy

tests_run:
				# make re -C Tests/
				unit_tests

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				# make fclean -C Tests/
				make fclean -C lib/my/

re:             fclean all