##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c 		\
				$(DIR)check_args.c  \
				$(DIR)check_calculations.c  \
				$(DIR)get_file.c  \
				$(DIR)print_infos_calculations.c  \
				$(DIR)putnbr_base.c  \
				$(DIR)check_binary_operators.c 		\
				$(DIR)check_live.c 				\
				$(DIR)check_ld.c 			\
				$(DIR)check_st.c 			\
				$(DIR)check_zjmp.c 			\

OBJ     =       $(SRC:.c=.o)

NAME    =       asm

END		=		\033[0m

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

LDFLAGS =		-L./../lib/my -lmy

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C ../lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
				@echo -e "\033[32m=========(   ASM COMPLETED  )=========$(END)"

clean:
				rm -f $(OBJ)
				make clean -C ../lib/my/
				make clean -C tests/
				@echo -e "\033[31m=========(    ASM CLEANED   )=========$(END)"

fclean:         clean
				rm -f $(NAME)
				make fclean -C ../lib/my
				make fclean -C tests/

re:             fclean all

tests_run:
	$(MAKE) -C tests/
	./unit_tests
	gcovr -e tests

debug:			CFLAGS += -g
debug:			re

.PHONY: all clean fclean re tests_run debug