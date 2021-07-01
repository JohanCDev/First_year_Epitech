##
## EPITECH PROJECT, 2020
## B-CPE-101-NAN-1-1-infinadd-johan.chrillesen
## File description:
## Makefile
##

SRC     =       infin_add.c

OBJ     =       $(SRC:.c=.o)

NAME    =       infin_add

CFLAGS  =       -Wall -Werror -Wshadow -Wextra -I include/

all:            $(NAME)

$(NAME):        $(OBJ)
				cd lib/my/ && make re
				cd ../../
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy
clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:             fclean all