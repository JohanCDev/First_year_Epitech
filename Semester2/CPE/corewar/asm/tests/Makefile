##
## EPITECH PROJECT, 2021
## B-CPE-201-NAN-2-1-corewar-johan.chrillesen
## File description:
## Makefile
##

SRC     =   ../src/get_file.c\
			../src/putnbr_base.c\
			test_my_asm.c\

CC      =    gcc

RM      =   rm -f

CFLAGS  = -I ../include/ -Wextra -Wall -L../../lib/my -lmy

TESTSFLAGS   =  --coverage -lcriterion

TEST_NAME    =  ../unit_tests

OBJ     =   $(SRC:.c=.o)

all: tests_run

clean:
	find -name "*.o" -delete
	find -name "*.gcno" -delete
	find -name "*.gcda" -delete

fclean:    clean
	$(RM) $(TEST_NAME)

tests_run: fclean $(OBJ)
	$(MAKE) -C ../../lib/my/
	$(CC) -o $(TEST_NAME) $(OBJ) $(TESTSFLAGS) $(CFLAGS)

re: fclean all

.PHONY: all clean fclean re tests_run