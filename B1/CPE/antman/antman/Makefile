##
## EPITECH PROJECT, 2021
## B-CPE-110-NAN-1-1-antman-tanguy.bellicha
## File description:
## Makefile
##

SRC		=		antman.c \
				files.c \
				list.c \
				check_different_words.c \
				check_images.c \
				hexa.c \

OBJ     =       $(SRC:.c=.o) \

NAME    =       antman

CFLAGS  =       -Wall -Wshadow -Wextra -I../include/ -g

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C ../lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L../lib/ -lmy

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)

re:             fclean all

.PHONY:			$(NAME)