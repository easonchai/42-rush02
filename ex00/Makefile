NAME = rush-02

SRCS = main.c ft_checks.c ft_checks2.c ft_getters.c ft_print.c \
		ft_read.c ft_solve.c ft_utils.c ft_setters.c ft_free.c \
		ft_validate.c ft_magic.c sub_main.c\

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

.c.o:
	@gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

clean:
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

${NAME}: 	${OBJS}
			@gcc -o ${NAME} ${OBJS} 
			@rm -f *.o

.PHONY: all fclean clean re
