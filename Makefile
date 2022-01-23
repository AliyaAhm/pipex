NAME = pipex

SRCS = src/pipex.c

HEADER = include/pipex.h

OBJ = ${SRCS:%.c=%.o}

LIB = libft/libft.a

CC = clang

FLAFS = -Wall -Wextra -Werror

RM = rm -rf

.PHONY: all clean fclean re bonus libft

all: libft ${NAME}

libft: 
	${MAKE} -C libft/

${NAME}: 	${OBJ}
			${CC} ${FLAGS} ${OBJ} ${LIB} -o ${NAME}

%.o : %.c ${HEADER}
		${CC} ${FLAGS} -c $< -o  $@

clean:
		${RM} ${OBJ}
		${MAKE} -C - libft/ clean

fclean: clean
		${MAKE} -C libft/ fclean
		${RM} ${NAME}
	
re:		fclean all