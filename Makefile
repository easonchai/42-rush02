NAME = rush-02

SRCS = srcs/

CFLAGS = -Wall -Wextra -Werror

all:		${NAME}

clean:
			rm -f ${SRCS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

${NAME}: 	${SRCS}
			gcc ${CFLAGS} ${SRCS} -o ${NAME}

.PHONY: all fclean clean re
