##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	my_runner.c		\
			fond.c		\
			character.c		\
			text.c		\
			spike.c		\
			destroy.c		\
			pause.c		\
			usage.c		\
			window.c		\
			event.c		\
			music.c		\
			add_to_list.c		\
			init_remove_list.c		\
			stock_map.c		\
			castle.c		\
			firework.c		\
			ending_win.c		\
			ending.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_runner

all:	clean fclean $(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -lcsfml-audio -lcsfml-graphics -lcsfml-system -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf -lm

valgrind:
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -lcsfml-audio -lcsfml-graphics -lcsfml-system -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf -lm -g3

warning:
		(cd ./lib/my/ && make)
		(cd ./lib/my_printf/ && make)
		gcc -o $(NAME) $(SRC) -lcsfml-audio -lcsfml-graphics -lcsfml-system -Llib/my/. -lmy -Llib/my_printf/. -lmy_printf -lm -Wall -Werror

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean $(NAME)

auteur:
		echo $(USER) > auteur
