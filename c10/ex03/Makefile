NAME = ft_hexdump
OBJS = ${SRC:%.c=%.o}
SRC = ft_hexdump.c ft_putnbr_base.c ft_strstr.c ft_char_is_printable.c ft_abs.c is_buffer_empty.c handle_buffer.c ft_read_stdin.c
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