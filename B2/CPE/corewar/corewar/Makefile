##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c  			\
				$(DIR)get_file.c		\

OBJ     =       $(SRC:.c=.o)

NAME    =       corewar

END		=		\033[0m

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

LDFLAGS =		-L./../lib/my -lmy

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C ../lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
				@echo -e "\033[32m=========(   COREWAR COMPLETED  )=========$(END)"

clean:
				rm -f $(OBJ)
				make clean -C ../lib/my/
				@echo -e "\033[31m=========(    COREWER CLEANED   )=========$(END)"

fclean:         clean
				rm -f $(NAME)
				make fclean -C ../lib/my

re:             fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY: all clean fclean re debug