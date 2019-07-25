NAME = bsq
SRC = ./src/main.c ./src/ft_atoi.c ./src/map_parsing.c ./src/utility.c ./src/grid_parsing.c ./src/map_solving.c
OBJS = ${SRC:%.c=%.o}
CFLAGS = -Wall -Wextra -Werror
DEBUG = debug

all: ${NAME}

${NAME}: $(OBJS)
		gcc -o ${NAME} ${OBJS}

${DEBUG}:
		gcc -o ${DEBUG} ${CFLAGS} -ggdb -fsanitize=address ${SRC}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}
		rm -f ${DEBUG}
		rm -Rf *.dSYM

re: fclean all
