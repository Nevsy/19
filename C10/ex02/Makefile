CC		= cc
SRCS	= ft_tail.c
OBJS	= $(SRCS:.c=.o)

RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

NAME	= ft_tail

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
