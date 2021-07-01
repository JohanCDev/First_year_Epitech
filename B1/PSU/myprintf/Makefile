##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

DIR		=		sources/

SRC     =       $(DIR)my_strlen.c \
				$(DIR)my_put_nbr.c \
				$(DIR)my_putchar.c \
				$(DIR)my_putstr.c \
				$(DIR)my_getnbr.c \
				$(DIR)my_putfloat.c \
				$(DIR)my_put_error.c \
				$(DIR)my_str_isalpha.c \
				$(DIR)my_str_isnum.c \
				$(DIR)my_pow.c \
				$(DIR)check_types.c \
				$(DIR)my_put_adress.c \
				$(DIR)my_printf.c \
				$(DIR)my_put_unsigned.c \
				$(DIR)check_params.c \
				$(DIR)my_putstr_nonprintable.c \
				$(DIR)my_strcpy.c \

NAME	=	libmy.a

RM 		= 	rm -rf

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re