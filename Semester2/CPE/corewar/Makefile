##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME    =       CoreDumpedWar

END		=		\033[0m

all:            $(NAME)

$(NAME):
		make -C lib/my/
		make -C asm/
		make -C corewar/
		@echo -e "\033[32m=========(  COMPLETED  )=========$(END)"

clean:
		make clean -C corewar/
		make clean -C asm/
		make clean -C lib/my/
		@echo -e "\033[31m=========(   CLEANED   )=========$(END)"

fclean:         clean
		make fclean -C corewar/
		make fclean -C asm/
		make fclean -C lib/my

re:             fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY: all clean fclean re debug