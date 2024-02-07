##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=		print_help.c	\
			update/update.c	\
			update/close_window.c	\
			update/buttons.c	\
			initialise/initialise_corners.c	\
			initialise/initialise_window.c	\
			draw/draw.c	\
			destroy/destroy_all.c	\
			set_planes.c	\
			add_lst.c	\
			add_plane.c	\
			update/update_timer.c	\

CFLAGS	=	-Wall -Wextra -Werror -I./include/	\
			-L./lib/my/ -lmy -l csfml-graphics 	\
			-l csfml-system -l csfml-audio -lm	\

SRC_LIB	=	lib/my/my_strcmp.c	\
			lib/my/mini_printf.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strlen.c	\
			lib/my/my_compute_power_rec.c	\

CFLAGS_LIB 	=	-I./include/ -Werror -Wall -Wextra

OBJ	=	$(SRC_LIB:.c=.o)

NAME	=	my_radar

SRC_TESTS =		tests/Test_check_file.c	\

FLAGS_TEST	=	-Wall -Wextra -Werror -I./include/	\
				-L./lib/my/ -lmy -l csfml-graphics 	\
				-l csfml-system -l csfml-audio -lm 	\
				-lcriterion --coverage	\

all: libmy.a
	gcc -o $(NAME) $(SRC) main.c $(CFLAGS)

libmy.a:	$(OBJ)
	gcc -c $(SRC_LIB) $(CFLAGS_LIB)
	ar rc lib/my/libmy.a $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f lib/my/libmy.a
	rm -f unit_tests
	rm -f $(NAME)

re: fclean all

unit_tests: re
	gcc -o unit_tests $(SRC_TESTS) $(SRC) $(FLAGS_TEST)

tests_run: unit_tests
	./unit_tests
