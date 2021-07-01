##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile lib
##

SRC	=	$(shell find -type f -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

END		=		\033[0m

CFLAGS	=	-Wall -Wshadow -Wextra

all:	$(NAME)
		@echo -e "\033[32m=========(   LIB COMPLETED  )=========$(END)"

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)
		@echo -e "\033[31m=========(    LIB CLEANED   )=========$(END)"

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
