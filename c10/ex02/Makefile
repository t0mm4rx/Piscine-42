NAME = ft_tail
OBJS = ${SRC:%.c=%.o}
SRC = ft_tail.c utils.c
CFLAGS = -Wall -Wextra -Werror
DEBUG = debug

all: ${NAME}

${NAME}: $(OBJS)
	gcc -o ${NAME} ${OBJS}

${DEBUG}:
	gcc -o ${DEBUG} ${CFLAGS} -g -fsanitize=address ${SRC}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	rm -f ${DEBUG}
	rm -Rf *.dSYM

re: fclean all