##
## EPITECH PROJECT, 2021
## B-CPE-110-NAN-1-1-antman-tanguy.bellicha
## File description:
## Makefile
##

SRC		=		giantman.c \
				uncompress_images.c \
				numbers.c \

OBJ     =       $(SRC:.c=.o) \

NAME    =       giantman

CFLAGS  =       -Wall -Wshadow -Wextra -I../include

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C ../lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L../lib/ -lmy -lm

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)

re:             fclean all

.PHONY:			$(NAME)