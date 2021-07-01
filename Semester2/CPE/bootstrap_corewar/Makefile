##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

CFLAGS	+=	-Wall -Wextra -I include

all:		$(NAME)

part1:
		make re -C ./part1

part2:
		make re -C ./part2

clean:
		make clean -C ./part1
		rm -f $(OBJ)

fclean:		clean
		make fclean -C ./part1
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
