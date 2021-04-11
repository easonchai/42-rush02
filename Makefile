NAME = rush-02

SRCS = main.c ft_checks.c ft_checks2.c ft_getters.c ft_print.c \
		ft_read.c ft_solve.c ft_splitter.c ft_utils.c

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

${NAME}: 	${OBJS}
			gcc -o ${NAME} ${OBJS} 

.PHONY: all fclean clean re
