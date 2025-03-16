SRC	=	src/main.c	\
		src/operation.c	\
		src/parentheses.c	\
		src/expression/evaluator.c	\
		src/expression/parser.c	\
		src/expression/part.c	\
		src/utils/list.c	\
		src/utils/delete_char.c	\
		src/utils/is_digit.c	\
		src/utils/strtod.c

NAME	=	calculator

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -O1

CPPFLAGS	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	find . -name "*~" -delete
	find . -name '#'*'#' -delete
	find . -name '*.gc*' -delete

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug:	fclean
debug:	CFLAGS += -ggdb3
debug:	all

.PHONY:	all $(NAME) clean fclean re debug
