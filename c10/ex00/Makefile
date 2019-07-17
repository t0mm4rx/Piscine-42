SRC = ft_display_file.c
OBJ = ft_display_file.o
NAME = ft_display_file

all: ${NAME}

${NAME}:
	gcc -c -Wall -Werror -Wextra ${SRC}
	gcc -o ${NAME} ${OBJ}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

.PHONY: all ${NAME} clean
