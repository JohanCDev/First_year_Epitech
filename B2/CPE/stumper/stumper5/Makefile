##
## EPITECH PROJECT, 2020
##my_radar
## File description:
## Make file for screensaver
##Makfile

MAIN	=	src/main.c

SRC	=	src/my_str_isnum.c \
		src/check_letter.c \
		src/play.c \
		src/my_str_to_word_array.c \
		src/open_and_read_file.c \
		src/get_word.c \
		src/initialize.c \
		src/free_all.c \

TEST_SRC	=	tests/test_check_letter.c	\
				tests/test_check_params.c	\
				tests/test_open_and_read_file.c	\
				tests/init_tests.c	\

NAME	=	hangman

OBJ	=	$(SRC:.c=.o)
OBJ	+=	$(MAIN:.c=.o)

CFLAGS	=	-I ./include -W -Wall -Wextra -Wshadow

TFLAGS	=	--coverage -lcriterion

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lm

tests_run:
		$(CC) -o unit_tests $(SRC) $(TEST_SRC) $(CFLAGS) $(TFLAGS)
		./unit_tests
		gcovr --exclude tests/
		gcovr --branches --exclude tests/

clean:
		rm -f $(OBJ)
		rm -f *.gcno
		rm -f *.gcda

fclean:		clean
		rm -f $(NAME)
		rm -f unit_tests

re:		fclean all
