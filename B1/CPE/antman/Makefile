##
## EPITECH PROJECT, 2021
## B-CPE-110-NAN-1-1-antman-tanguy.bellicha
## File description:
## Makefile
##

CFLAGS  =       -Wall -Wshadow -Wextra -I../include

all:            antman giantman

antman :
				make re -C ./antman/

giantman :
				make re -C ./giantman/

clean:
				rm -f $(OBJ)
				make clean -C ./lib/my
				make clean -C ./antman/
				make clean -C ./giantman/

fclean:         clean
				rm -f $(NAME)
				make fclean -C ./lib/my
				make fclean -C ./antman/
				make fclean -C ./giantman/

re:             fclean all antman giantman

.PHONY:			antman giantman