##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

CFLAGS	+=	-Wall -Wextra -I ./include

all:	step1 step2 step3 step4 step5

step1:
		gcc step1/yolotron_asm.c my_str_to_word_array.c -o yolotron-asm $(CFLAGS)

clean:
		# make clean -C ./part1
		rm -f $(OBJ)

fclean:		clean
		# make fclean -c ./part1
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re