CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB_PATH = ./libft/libft.a

NAME = push_swap

BON_NAME = checker

FILES = push_swap.c \
initial_stack_check.c \
stack_saving_freeing.c \
raw_stack_movement.c \
stack_managing.c \
stack_sort_small.c \
stack_ordering.c \
stack_algoritm.c \
radix_comp.c \
stack_mv_print.c

OBJ = ${FILES:%.c=%.o}

BON_FILES = checker.c \
checker_check.c \
checker_input.c \
checker_move.c \
checker_stack_creation.c

BON_OBJ = ${BON_FILES:%.c=%.o}

all : ${NAME}

${NAME} : ${LIB_PATH} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${LIB_PATH} -o ${NAME}

${OBJ} : ${FILES}
	${CC} ${CFLAGS} -c ${FILES} 
${LIB_PATH} :
	make -C ./libft

re :	fclean all

clean :
	@${RM} ${OBJ} ${BON_OBJ}; make fclean -C ./libft

bonus : ${BON_NAME}

${BON_NAME} : ${LIB_PATH} ${BON_OBJ}
	${CC} ${CFLAGS} ${BON_OBJ} ${LIB_PATH} -o ${BON_NAME}

${BON_OBJ} : ${BON_FILES}
	${CC} ${CFLAGS} -c ${BON_FILES} 

fclean : clean
	@${RM} ${NAME} ${BON_NAME}

.PHONY: all clean fclean bonus re
