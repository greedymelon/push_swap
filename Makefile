CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = push_swap

FILES = push_swap.c \
initial_stack_check.c

OBJ = ${FILES:%.c=%.o}

all : ${NAME}

${NAME} : libft.a ${OBJ}
	@${CC} ${CFLAGS} ./libft/libft.a ${OBJ} -o ${NAME}

${OBJ} : ${FILES}
	@${CC} ${CFLAGS} push_swap.h -c ${FILES} 
libft.a :
	make -C ./libft

re :	fclean all

clean :
	@${RM} ${OBJ}; make fclean -C ./libft


fclean : clean
	@${RM} ${NAME} 

.PHONY: all clean fclean bonus re
