NAME = Rush02

SRCS = src/main.c src/rush02.c src/technicals.c

OBJS = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
