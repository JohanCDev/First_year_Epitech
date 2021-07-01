##
## EPITECH PROJECT, 2021
## B-CPE-110-NAN-1-1-antman-tanguy.bellicha
## File description:
## Makefile
##

CFLAGS  =         -Wall -Wshadow -Wextra -I../include

all:                solver generator

solver :
				make re -C ./solver/

generator :
				make re -C ./generator/

original :
				gcc -o original original.c

clean:
				rm -f $(OBJ)
				make clean -C ./solver/
				make clean -C ./generator/

fclean:            clean
				rm -f $(NAME)
				make fclean -C ./solver/
				make fclean -C ./generator/

re:                 fclean all solver generator

.PHONY:			solver generator