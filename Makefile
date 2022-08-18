CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB_PATH = ./libft/libft.a

NAME = push_swap

FILES = push_swap.c \
initial_stack_check.c \
stack_saving_freeing.c \
raw_stack_movement.c \
stack_managing.c \
test_move.c	\
stack_sort.c

OBJ = ${FILES:%.c=%.o}

all : ${NAME}

${NAME} : ${LIB_PATH} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${LIB_PATH} -o ${NAME}

${OBJ} : ${FILES}
	${CC} ${CFLAGS} -c ${FILES} 
${LIB_PATH} :
	make -C ./libft

re :	fclean all

clean :
	@${RM} ${OBJ}; make fclean -C ./libft


fclean : clean
	@${RM} ${NAME} 

.PHONY: all clean fclean bonus re
