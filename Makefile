##
## EPITECH PROJECT, 2019
## my_makefile
## File description:
## makefile
##

SRC	=	$(shell find src/ -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f src/*~
	rm -f vgcore.*
	rm -rf .vscode .dist

re:	fclean all
